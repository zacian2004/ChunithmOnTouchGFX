#include <gui/gameplay_screen/GameplayView.hpp>
#include <gui/gameplay_screen/GameplayPresenter.hpp>
#include <gui/model/Model.hpp>
#include <math.h>

GameplayPresenter::GameplayPresenter(GameplayView& v)
	: Presenter()   // khởi Presenter base
	, view(v)
	// Lấy Model& từ FrontendApplication đã được sửa để có getModel()
	, model(static_cast<FrontendApplication&>(*touchgfx::Application::getInstance()).getModel())
{
	model.bind(this);
}

constexpr int JUDGE_LINE_Y    = 221;
constexpr int PERFECT_RANGE_Y = 12;
constexpr int GOOD_RANGE_Y    = 24;


void GameplayPresenter::activate()
{

}

void GameplayPresenter::deactivate()
{

}

void GameplayPresenter::onButtonPressed(uint8_t lane)
{
    // 1) Lấy thông tin note từ View
    uint8_t noteLane = view.getCurrentLane();
    int     noteY    = view.getCurrentNoteY();

    // 2) Tính kết quả bấm
    HitResult result;
    if (lane == noteLane) {
        int dist = abs(noteY - JUDGE_LINE_Y);
        if (dist <= PERFECT_RANGE_Y) result = PERFECT;
        else if (dist <= GOOD_RANGE_Y && dist > PERFECT_RANGE_Y) result = GOOD;
        else result = MISS;
    } else return;

    // Cập nhật trực tiếp biến trong presenter
    switch (result)
    {
        case PERFECT: p++; 		break;
        case GOOD:    g++;    	break;
        case MISS:    m++;    	break;
    }

    // 4) Cho View hiển thị hiệu ứng
    view.showHitFeedback(result);

    // 5) Ẩn note hiện tại để Presenter sẽ spawn note kế tiếp
    view.hideNote();
    // (hoặc gọi một API chung như view.hideActiveNote())
}

int GameplayPresenter::getSong()
{
	return model.getSelectedSong();
}
