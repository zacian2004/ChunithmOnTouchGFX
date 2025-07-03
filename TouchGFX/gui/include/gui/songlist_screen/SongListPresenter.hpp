#ifndef SONGLISTPRESENTER_HPP
#define SONGLISTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <gui/model/Model.hpp>
#include <mvp/Presenter.hpp>
#include <cstdint>

class SongListView;

class SongListPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SongListPresenter(SongListView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate() override;

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate() override;

    virtual ~SongListPresenter() {}

    void selectSong(uint8_t index);

private:
    SongListPresenter();

    SongListView& view;
    Model& model;
};

#endif // SONGLISTPRESENTER_HPP
