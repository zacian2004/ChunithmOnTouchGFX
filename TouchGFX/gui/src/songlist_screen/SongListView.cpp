#include <gui/songlist_screen/SongListView.hpp>

SongListView::SongListView()
{

}

void SongListView::setupScreen()
{
    SongListViewBase::setupScreen();
}

void SongListView::tearDownScreen()
{
    SongListViewBase::tearDownScreen();
}

void SongListView::song1Clicked()
{
	presenter->selectSong(0);
    application().gotoGameplayScreenNoTransition();
}

void SongListView::song2Clicked()
{
	presenter->selectSong(1);
    application().gotoGameplayScreenNoTransition();
}

void SongListView::song3Clicked()
{
	presenter->selectSong(2);
    application().gotoGameplayScreenNoTransition();
}

void SongListView::song4Clicked()
{
	presenter->selectSong(3);
    application().gotoGameplayScreenNoTransition();
}
