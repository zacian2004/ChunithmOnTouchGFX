#ifndef RESULTVIEW_HPP
#define RESULTVIEW_HPP

#include <gui_generated/result_screen/ResultViewBase.hpp>
#include <gui/result_screen/ResultPresenter.hpp>

class ResultView : public ResultViewBase
{
public:
    ResultView();
    virtual ~ResultView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setResults(int scorePct, int perfect, int good, int miss);
private:
    static const int BUFFER_SIZE = 10;
    // Các buffer chứa chuỗi hiển thị
    Unicode::UnicodeChar scoreBuffer[BUFFER_SIZE];
    Unicode::UnicodeChar perfectBuffer[BUFFER_SIZE];
    Unicode::UnicodeChar goodBuffer[BUFFER_SIZE];
    Unicode::UnicodeChar missBuffer[BUFFER_SIZE];
};

#endif // RESULTVIEW_HPP
