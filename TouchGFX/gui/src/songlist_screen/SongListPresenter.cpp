#include <gui/songlist_screen/SongListPresenter.hpp>
#include <gui/songlist_screen/SongListView.hpp>

SongListPresenter::SongListPresenter(SongListView& v)
	: Presenter()   // khởi Presenter base
	, view(v)
	// Lấy Model& từ FrontendApplication đã được sửa để có getModel()
	, model(static_cast<FrontendApplication&>(*touchgfx::Application::getInstance()).getModel())
{
	model.bind(this);
}

void SongListPresenter::activate()
{

}

void SongListPresenter::deactivate()
{

}

void SongListPresenter::selectSong(uint8_t index)
{
	model.setSelectedSong(index);
}
