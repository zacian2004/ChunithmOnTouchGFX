#include <gui/result_screen/ResultView.hpp>
#include <gui/result_screen/ResultPresenter.hpp>
#include <gui/model/Model.hpp>

ResultPresenter::ResultPresenter(ResultView& v)
	: view(v)
{

}

void ResultPresenter::activate()
{
	// Lấy stats từ Model
	int scorePct = model->getFinalScore();       // stored as percent
	int perfect  = model->getPerfectCount();
	int good     = model->getGoodCount();
	int miss     = model->getMissCount();

	// Đưa lên View
	view.setResults(scorePct, perfect, good, miss);
}

void ResultPresenter::deactivate()
{

}
