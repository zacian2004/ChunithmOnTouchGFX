#ifndef RESULTPRESENTER_HPP
#define RESULTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ResultView;

class ResultPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ResultPresenter(ResultView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ResultPresenter() {}

private:
    ResultPresenter();

    ResultView& view;
};

#endif // RESULTPRESENTER_HPP
