#ifndef SONGLISTVIEW_HPP
#define SONGLISTVIEW_HPP

#include <gui_generated/songlist_screen/SongListViewBase.hpp>
#include <gui/songlist_screen/SongListPresenter.hpp>

class SongListView : public SongListViewBase
{
public:
    SongListView();
    virtual ~SongListView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void song1Clicked() override;
	virtual void song2Clicked() override;
	virtual void song3Clicked() override;
	virtual void song4Clicked() override;
protected:
};

#endif // SONGLISTVIEW_HPP
