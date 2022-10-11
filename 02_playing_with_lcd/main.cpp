#include "mbed.h"
#include "stm32746g_discovery_lcd.h"
#include <iostream>
#include <cctype>


void displayText(uint16_t x,uint16_t y, std::uint8_t* text, uint32_t back_color, uint32_t text_color ) {

        BSP_LCD_SetBackColor(back_color);
        BSP_LCD_SetTextColor(text_color);
        BSP_LCD_DisplayStringAt(x, y, (uint8_t *)text, CENTER_MODE);
}

int main()
{
     BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FB_START_ADDRESS);
    BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);
    

    while(1) {
        BSP_LCD_Clear(LCD_COLOR_BLACK);
        BSP_LCD_SetFont(&LCD_DEFAULT_FONT);
        displayText(0,150,(uint8_t *)"Team DOTS",LCD_COLOR_WHITE,LCD_COLOR_DARKBLUE);
        HAL_Delay(500);
        
        displayText(0,100,(uint8_t *)"Pavel Vacha",LCD_COLOR_BLACK,LCD_COLOR_ORANGE);
        HAL_Delay(500);
        
        displayText(0,150,(uint8_t *)"Jakub Silhan",LCD_COLOR_BLACK,LCD_COLOR_ORANGE);
        HAL_Delay(500);
        
        displayText(0,200,(uint8_t *)"!!!!!",LCD_COLOR_BLACK,LCD_COLOR_ORANGE);
        HAL_Delay(50000);
    }
}

