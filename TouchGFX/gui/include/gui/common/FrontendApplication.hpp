#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }

    Model& getModel() { return model; }
	const Model& getModel() const { return model; }
private:
};

#endif // FRONTENDAPPLICATION_HPP
