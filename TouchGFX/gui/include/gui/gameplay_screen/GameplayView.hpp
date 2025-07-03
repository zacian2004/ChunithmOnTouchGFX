#ifndef GAMEPLAYVIEW_HPP
#define GAMEPLAYVIEW_HPP

#include <gui_generated/gameplay_screen/GameplayViewBase.hpp>
#include <gui/gameplay_screen/GameplayPresenter.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>

enum HitResult {PERFECT, GOOD, MISS};

class GameplayView : public GameplayViewBase
{
public:
    GameplayView();
    virtual ~GameplayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    virtual void tapLane1();
    virtual void tapLane2();
    virtual void tapLane3();
    virtual void tapLane4();

    /// Trả về lane của note đang active (theo sequence)
    uint8_t getCurrentLane() const {
        // sequenceIdx đã tăng lên sau khi spawn, nên note hiện tại là sequenceIdx-1
        switch (songNo)
        {
        case 0: return chart1[sequenceIdx - 1];
        case 1: return chart2[sequenceIdx - 1];
        case 2: return chart3[sequenceIdx - 1];
        case 3: return chart4[sequenceIdx - 1];
        }
    	//        return chart[sequenceIdx-1];
    }
    /// Trả về Y của note đang active
    int getCurrentNoteY() const {
        return tickCount;
    }

    /** Hiển thị hiệu ứng Perfect/Good/Miss trên note */
    void showHitFeedback(HitResult result);
    /** Ẩn note hiện hành và reset border về mặc định */
    void hideNote();

    void goToResultScreen() {
		application().gotoResultScreenNoTransition();
	}

protected:
    uint32_t tickCount;
private:
    int chart1[50] = {0,1,2,3,0,2,1,3};
    int chart2[50] = {0,1,0,2,0,3,0,2};
    int chart3[50] = {1,2,3,2,1,0,1,2};
	int chart4[50] = {2,3,1,0,1,2,0,3};
    int chartLength = 8;
    int songNo;

    int sequenceIdx  = 0;   // vị trí tiếp theo trong sequence
    bool noteActive  = false;
  // Scoring
    int totalNotes 		= 0;
    int successfulHits 	= 0;
    int perfectHits 	= 0;
    int goodHits 		= 0;
    int missHits 		= 0;

    // posX của note hiện tại
    int currentNoteX = 0;
    // hằng số layout
    static constexpr int START_X   = 0;
    static constexpr int SPACING_X = 60;
    static constexpr int END_Y     = 250;
    static constexpr int SPEED_Y   = 3;   // pixels mỗi tick
};

#endif // GAMEPLAYVIEW_HPP
