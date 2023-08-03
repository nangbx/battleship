/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/homescreen_screen/HomeScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

HomeScreenViewBase::HomeScreenViewBase() :
    buttonCallback(this, &HomeScreenViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 240, 320);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box1.setPosition(0, 0, 240, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box1);

    image1.setXY(10, 48);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_BATTLESHIP_ID));
    add(image1);

    image2.setXY(182, 14);
    image2.setBitmap(touchgfx::Bitmap(BITMAP_SHIP2_ID));
    add(image2);

    image3.setXY(84, 100);
    image3.setBitmap(touchgfx::Bitmap(BITMAP_SHIP31_ID));
    add(image3);

    image4.setXY(9, 137);
    image4.setBitmap(touchgfx::Bitmap(BITMAP_SHIP4_ID));
    add(image4);

    buttonWithLabel1.setXY(33, 208);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_SMALL_ROUND_ACTIVE_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_50_SMALL_ROUND_ACTIVE_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T___SINGLEUSE_71D7));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);
    add(buttonWithLabel1);
}

HomeScreenViewBase::~HomeScreenViewBase()
{

}

void HomeScreenViewBase::setupScreen()
{

}

void HomeScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to GameScreen
        //Go to GameScreen with screen transition towards East
        application().gotoGameScreenScreenSlideTransitionEast();
    }
}