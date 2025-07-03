#include <gui/gameplay_screen/GameplayView.hpp>
#include <gui/gameplay_screen/GameplayPresenter.hpp>
#include <touchgfx/Color.hpp>
#include <gui/model/Model.hpp>
#include <touchgfx/Unicode.hpp>
#include <math.h>

GameplayView::GameplayView()
{
	 tickCount = 0;
}

static const uint16_t COLOR_PERFECT = touchgfx::Color::getColorFromRGB(0, 255, 0);
static const uint16_t COLOR_GOOD    = touchgfx::Color::getColorFromRGB(255, 255, 0);
static const uint16_t COLOR_MISS    = touchgfx::Color::getColorFromRGB(255,   0, 0);


void GameplayView::setupScreen()
{
	GameplayViewBase::setupScreen();
	songNo = presenter->getSong();
}

void GameplayView::tearDownScreen()
{
    GameplayViewBase::tearDownScreen();
}

void GameplayView::handleTickEvent()
{
	GameplayViewBase::handleTickEvent();
    if (!noteActive)
    {
        // chưa có note nào active → spawn tiếp nếu còn sequence
        if (sequenceIdx >= chartLength)
        {
        	// hết sequence → chuyển sang Result
            application().gotoResultScreenNoTransition();
            return;
        }
//        uint8_t lane = chart[sequenceIdx++];
        uint8_t lane;
        switch (songNo)
        {
        case 0: lane = chart1[sequenceIdx++];break;
        case 1: lane = chart2[sequenceIdx++];break;
        case 2: lane = chart3[sequenceIdx++];break;
        case 3: lane = chart4[sequenceIdx++];break;
        }
        currentNoteX = START_X + lane * SPACING_X;
        tickCount    = 0;
        noteActive   = true;
    }

    // move note active
    tickCount += SPEED_Y;
    int y = tickCount;

    // cập nhật widget
    tapNote.setX(currentNoteX);
    tapNote.setY(y);
    tapNote.setVisible(true);

    // nếu đã qua END_Y → cull (miss) và cho phép spawn tiếp
    if (y >= END_Y)
    {
    	this->showHitFeedback(MISS);
        tapNote.setVisible(false);
        noteActive = false;
    }

    // redraw
    invalidate();
}

void GameplayView::tapLane1()
{
    presenter->onButtonPressed(0);
}

void GameplayView::tapLane2()
{
    presenter->onButtonPressed(1);
}

void GameplayView::tapLane3()
{
    presenter->onButtonPressed(0);
}

void GameplayView::tapLane4()
{
    presenter->onButtonPressed(1);
}

void GameplayView::showHitFeedback(HitResult result)
{
    // Chọn màu theo result
    touchgfx::colortype c;
    const char* txt = nullptr;
    switch (result)
    {
    case PERFECT: c = COLOR_PERFECT; txt = "PERFECT"; 	break;
    case GOOD:    c = COLOR_GOOD;    txt = "GOOD";		break;
    case MISS:    c = COLOR_MISS;    txt = "MISS";		break;
    }
    Unicode::snprintf(feedbackTextBuffer, 10, "%s", txt);
    feedbackText.setWildcard(feedbackTextBuffer);
    feedbackText.resizeToCurrentText();
    // Đổi border của tapNote
    feedbackText.setColor(c);
    feedbackText.setVisible(true);
    feedbackText.invalidate();
}

void GameplayView::hideNote()
{
    // Ẩn note
    tapNote.setVisible(false);
    // Reset border về trắng
    noteActive = false;
    tapNote.invalidate();
}
