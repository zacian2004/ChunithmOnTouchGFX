#include <gui/result_screen/ResultView.hpp>
#include <touchgfx/Unicode.hpp>

ResultView::ResultView()
{

}

void ResultView::setupScreen()
{
    ResultViewBase::setupScreen();
}

void ResultView::tearDownScreen()
{
    ResultViewBase::tearDownScreen();
}

void ResultView::setResults(int scorePct, int perfect, int good, int miss)
{
    // Score (%)
    Unicode::snprintf(scoreBuffer, BUFFER_SIZE, "%d%%", scorePct);
    resultText_1.setWildcard(scoreBuffer);
    resultText_1.resizeToCurrentText();
    resultText_1.invalidate();

    // Perfect
    Unicode::snprintf(perfectBuffer, BUFFER_SIZE, "%d", perfect);
    resultText_2.setWildcard(perfectBuffer);
    resultText_2.resizeToCurrentText();
    resultText_2.invalidate();

    // Good
    Unicode::snprintf(goodBuffer, BUFFER_SIZE, "%d", good);
    resultText_3.setWildcard(goodBuffer);
    resultText_3.resizeToCurrentText();
    resultText_3.invalidate();

    // Miss
    Unicode::snprintf(missBuffer, BUFFER_SIZE, "%d", miss);
    resultText_4.setWildcard(missBuffer);
    resultText_4.resizeToCurrentText();
    resultText_4.invalidate();
}
