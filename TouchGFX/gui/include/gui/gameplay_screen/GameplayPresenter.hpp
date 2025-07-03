#ifndef GAMEPLAYPRESENTER_HPP
#define GAMEPLAYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>


class GameplayView;

class GameplayPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    GameplayPresenter(GameplayView& v);

    /**
     * The activate function is callged automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~GameplayPresenter() {}

    void onButtonPressed(uint8_t lane);
    int getSong();

private:
    GameplayPresenter() = delete;
    GameplayView& view;
    Model& model;
    int p, g, m;
};

#endif // GAMEPLAYPRESENTER_HPP
