/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef OPPONENTSCREENVIEWBASE_HPP
#define OPPONENTSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/opponentscreen_screen/OpponentScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ScalableImage.hpp>
#include <touchgfx/containers/Container.hpp>

class OpponentScreenViewBase : public touchgfx::View<OpponentScreenPresenter>
{
public:
    OpponentScreenViewBase();
    virtual ~OpponentScreenViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box bg;
    touchgfx::ScalableImage board2;
    touchgfx::Container boat2;
    touchgfx::ScalableImage scalableImage2_1_1;
    touchgfx::ScalableImage scalableImage2_3;
    touchgfx::Container boat5;
    touchgfx::ScalableImage scalableImage2_2_1_2;
    touchgfx::ScalableImage scalableImage2_2_1_1_1;
    touchgfx::ScalableImage scalableImage2_2_1_1_1_1;
    touchgfx::ScalableImage scalableImage2_1_2_1;
    touchgfx::ScalableImage scalableImage2_4_1;
    touchgfx::Container boat4;
    touchgfx::ScalableImage scalableImage2_2_1;
    touchgfx::ScalableImage scalableImage2_2_1_1;
    touchgfx::ScalableImage scalableImage2_1_2;
    touchgfx::ScalableImage scalableImage2_4;
    touchgfx::Container boat3;
    touchgfx::ScalableImage scalableImage2_2;
    touchgfx::ScalableImage scalableImage2_1;
    touchgfx::ScalableImage scalableImage2;
    touchgfx::Container boat2_r;
    touchgfx::ScalableImage scalableImage1_1_1_1;
    touchgfx::ScalableImage scalableImage1_2;
    touchgfx::Container boat5_r;
    touchgfx::ScalableImage scalableImage1_1_1_2_1;
    touchgfx::ScalableImage scalableImage1_1_2_1;
    touchgfx::ScalableImage scalableImage1_3_2;
    touchgfx::ScalableImage scalableImage1_3_1_1;
    touchgfx::ScalableImage scalableImage1_3_1_1_1;
    touchgfx::Container boat4_r;
    touchgfx::ScalableImage scalableImage1_1_1_2;
    touchgfx::ScalableImage scalableImage1_1_2;
    touchgfx::ScalableImage scalableImage1_3;
    touchgfx::ScalableImage scalableImage1_3_1;
    touchgfx::Container boat3_r;
    touchgfx::ScalableImage scalableImage1_1_1;
    touchgfx::ScalableImage scalableImage1_1;
    touchgfx::ScalableImage scalableImage1_2_1;
    touchgfx::ScalableImage title2;
    touchgfx::ScalableImage select;

private:

};

#endif // OPPONENTSCREENVIEWBASE_HPP
