/**
 * \author  Tilen Majerle
 * \brief   GUI Widget handle manager
 *	
\verbatim
   ----------------------------------------------------------------------
    Copyright (c) 2017 Tilen Majerle

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software, 
    and to permit persons to whom the Software is furnished to do so, 
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
    AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------
\endverbatim
 */
#ifndef GUI_WIDGET_H
#define GUI_WIDGET_H

/* C++ detection */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup        GUI_WIDGETS Widgets
 * \brief           Group for visible widgets on screen
 * \{
 */
    
/**
 * \defgroup        GUI_WIDGETS_CORE Core widget functions
 * \brief           Core functions for all widgets
 *
 * Use can use all function which do not start with <b>__GUI</b> which indicate private functions.
 *
 * \{
 */
#include "gui.h"
#include "gui_draw.h"

/**
 * \defgroup        GUI_WIDGET_ID_Values Predefined ID values
 * \brief           Macros for fast ID setup
 * \{
 */  
    
#define GUI_ID_WINDOW_BASE          ((uint16_t)0x0000)                          /*!< Window base ID */
#define GUI_ID_WINDOW_1             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0001))   /*!< Window object ID 1 */
#define GUI_ID_WINDOW_2             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0002))   /*!< Window object ID 2 */
#define GUI_ID_WINDOW_3             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0003))   /*!< Window object ID 3 */
#define GUI_ID_WINDOW_4             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0004))   /*!< Window object ID 4 */
#define GUI_ID_WINDOW_5             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0005))   /*!< Window object ID 5 */
#define GUI_ID_WINDOW_6             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0006))   /*!< Window object ID 6 */
#define GUI_ID_WINDOW_7             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0007))   /*!< Window object ID 7 */
#define GUI_ID_WINDOW_8             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0008))   /*!< Window object ID 8 */
#define GUI_ID_WINDOW_9             ((uint16_t)(GUI_ID_WINDOW_BASE + 0x0009))   /*!< Window object ID 9 */
#define GUI_ID_WINDOW_10            ((uint16_t)(GUI_ID_WINDOW_BASE + 0x000A))   /*!< Window object ID 10 */
    
#define GUI_ID_BUTTON_BASE          ((uint16_t)0x0100)                          /*!< Button base ID */
#define GUI_ID_BUTTON_1             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0001))   /*!< Button object ID 1 */
#define GUI_ID_BUTTON_2             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0002))   /*!< Button object ID 2 */
#define GUI_ID_BUTTON_3             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0003))   /*!< Button object ID 3 */
#define GUI_ID_BUTTON_4             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0004))   /*!< Button object ID 4 */
#define GUI_ID_BUTTON_5             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0005))   /*!< Button object ID 5 */
#define GUI_ID_BUTTON_6             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0006))   /*!< Button object ID 6 */
#define GUI_ID_BUTTON_7             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0007))   /*!< Button object ID 7 */
#define GUI_ID_BUTTON_8             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0008))   /*!< Button object ID 8 */
#define GUI_ID_BUTTON_9             ((uint16_t)(GUI_ID_BUTTON_BASE + 0x0009))   /*!< Button object ID 9 */
#define GUI_ID_BUTTON_10            ((uint16_t)(GUI_ID_BUTTON_BASE + 0x000A))   /*!< Button object ID 10 */
    
/**
 * \}
 */
 
/**
 * \defgroup        WIDGET_CREATE_FLAGS Flags for widget create
 * \brief           A list of flags supported for widget creation
 *
 * List of flags used on \ref __GUI_WIDGET_Create function when creating new widget
 * 
 * \{
 */
#define GUI_FLAG_WIDGET_CREATE_PARENT_DESKTOP       0x01 /*!< Indicates parent object of widget should be desktop window */

/**
 * \}
 */

#if defined(GUI_INTERNAL) || defined(DOXYGEN)
/**
 * \defgroup        WIDGET_Private Private functions
 * \brief           Private widget functions and enumerations.
 *
 * \note            Since they are not thread safe, they can only be used when inside GUI library.
 *                  It means they can be used in custom widget implementations where thread safety is guaranteed
 *
 * \{
 */

/**
 * \brief           Get absolute X position on LCD for specific widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          X position on LCD
 * \hideinitializer
 */
GUI_Dim_t __GUI_WIDGET_GetAbsoluteX(GUI_HANDLE_p h);

/**
 * \brief           Get absolute Y position on LCD for specific widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          Y position on LCD
 * \hideinitializer
 */
GUI_Dim_t __GUI_WIDGET_GetAbsoluteY(GUI_HANDLE_p h);

/**
 * \brief           Invalidate widget for redraw 
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_Invalidate(GUI_HANDLE_p h);

/**
 * \brief           Invalidate widget and parent widget for redraw 
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_InvalidateWithParent(GUI_HANDLE_p h);

/**
 * \brief           Set X and Y coordinates relative to parent object
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       x: X position relative to parent
 * \param[in]       y: Y position relative to parent
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_SetXY(GUI_HANDLE_p h, GUI_iDim_t x, GUI_iDim_t y);

/**
 * \brief           Set widget size
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       wi: Widget width
 * \param[in]       hi: Widget height
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_SetSize(GUI_HANDLE_p h, GUI_Dim_t wi, GUI_Dim_t hi);

/**
 * \brief           Enable 3D mode on widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_Enable3DStyle(GUI_HANDLE_p h);

/**
 * \brief           Disable 3D mode on widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_Disable3DStyle(GUI_HANDLE_p h);

/**
 * \brief           Set font used for widget drawing
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       *font: Pointer to \ref GUI_FONT_t structure with font information
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_SetFont(GUI_HANDLE_p h, const GUI_FONT_t* font);

/**
 * \brief           Set text for widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 *
 * \note            When memory for text is dynamically allocated, text will be copied to allocated memory,
 *                     otherwise it will just set the pointer to new text.
 *                     Any changes on this text after function call will affect on later results
 *
 * \param[in,out]   h: Widget handle
 * \param[in]       *text: Pointer to text to set
 * \retval          1: Successful
 * \retval          0: Failed
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_SetText(GUI_HANDLE_p h, const GUI_Char* text);

/**
 * \brief           Allocate text memory for widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       size: Number of bytes to allocate
 * \retval          1: Successful
 * \retval          0: Failed
 * \sa              __GUI_WIDGET_FreeTextMemory
 * \sa              GUI_WIDGET_AllocTextMemory
 * \sa              GUI_WIDGET_FreeTextMemory
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_AllocTextMemory(GUI_HANDLE_p h, uint32_t size);

/**
 * \brief           Free text memory for widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Successful
 * \retval          0: Failed
 * \sa              __GUI_WIDGET_AllocTextMemory
 * \sa              GUI_WIDGET_AllocTextMemory
 * \sa              GUI_WIDGET_FreeTextMemory
 * \hideinitializer
 */
uint8_t __GUI_WIDGET_FreeTextMemory(GUI_HANDLE_p h);

/**
 * \brief           Create new widget and add it to linked list to parent object
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in]       *widget: Pointer to \ref GUI_WIDGET_t structure with widget description
 * \param[in]       id: Widget unique ID to use for identity for callback processing
 * \param[in]       x: Widget X position relative to parent widget
 * \param[in]       y: Widget Y position relative to parent widget
 * \param[in]       width: Widget width in units of pixels
 * \param[in]       height: Widget height in uints of pixels
 * \param[in]       flags: Flags for create procedure
 * \retval          > 0: \ref GUI_HANDLE_p object of created widget
 * \retval          0: Widget creation failed
 * \sa              __GUI_WIDGET_Remove
 */
GUI_HANDLE_p __GUI_WIDGET_Create(const GUI_WIDGET_t* widget, GUI_ID_t id, GUI_iDim_t x, GUI_iDim_t y, GUI_Dim_t width, GUI_Dim_t height, uint8_t flags);

/**
 * \brief           Remove widget and all of its children widgets
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param           *h: Pointer to \ref GUI_HANDLE_p structure to remove widget
 *                      Pointer will be invalidated and set to 0
 * \retval          0: Failed
 * \retval          1: Success
 * \sa              __GUI_WIDGET_Create
 */
uint8_t __GUI_WIDGET_Remove(GUI_HANDLE_p* h);

/**
 * \brief           Show widget from visible area
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Widget shown
 * \retval          0: Widget not shown
 * \sa              __GUI_WIDGET_Hide
 */
uint8_t __GUI_WIDGET_Show(GUI_HANDLE_p h);

/**
 * \brief           Hide widget from visible area
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Widget hidden
 * \retval          0: Widget not hidden
 * \sa              __GUI_WIDGET_Show
 */
uint8_t __GUI_WIDGET_Hide(GUI_HANDLE_p h);

/**
 * \brief           Set width of widget in units of pixels
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Width in units of pixels
 * \retval          1: Successful
 * \retval          1: Failed
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetWidthPercent
 * \sa              GUI_WIDGET_SetHeightPercent
 */
uint8_t __GUI_WIDGET_SetWidth(GUI_HANDLE_p h, GUI_Dim_t width);

/**
 * \brief           Set height of widget in units of pixels
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       height: Height in units of pixels
 * \retval          1: Successful
 * \retval          1: Failed
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetWidthPercent
 * \sa              GUI_WIDGET_SetHeightPercent
 */
uint8_t __GUI_WIDGET_SetHeight(GUI_HANDLE_p h, GUI_Dim_t height);

/**
 * \brief           Set width of widget in percentage relative to parent widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Width in percentage
 * \retval          1: Successful
 * \retval          1: Failed
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetHeightPercent
 */
uint8_t __GUI_WIDGET_SetWidthPercent(GUI_HANDLE_p h, GUI_Dim_t width);

/**
 * \brief           Set height of widget in percentage relative to parent widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Height in percentage
 * \retval          1: Successful
 * \retval          1: Failed
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetWidthPercent
 */
uint8_t __GUI_WIDGET_SetHeightPercent(GUI_HANDLE_p h, GUI_Dim_t height);

/**
 * \brief           Check if widget is children of parent
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in]       h: Widget handle to test
 * \param[in]       parent: Parent widget handle to test if is parent
 * \retval          1: Widget handle is in tree of parent handle
 * \retval          0: Widget handle is not in tree of parent handle
 */
uint8_t __GUI_WIDGET_IsChildOf(GUI_HANDLE_p h, GUI_HANDLE_p parent);

//Fonts and text manupulation
uint8_t __GUI_WIDGET_IsFontAndTextSet(GUI_HANDLE_p h);
uint8_t __GUI_WIDGET_ProcessTextKey(GUI_HANDLE_p h, __GUI_KeyboardData_t* key);

#define __GUI_WIDGET_GetPaddingTop(h)               (uint8_t)(((__GH(h)->Padding >> 24) & 0xFFUL))
#define __GUI_WIDGET_GetPaddingRight(h)             (uint8_t)(((__GH(h)->Padding >> 16) & 0xFFUL))
#define __GUI_WIDGET_GetPaddingBottom(h)            (uint8_t)(((__GH(h)->Padding >>  8) & 0xFFUL))
#define __GUI_WIDGET_GetPaddingLeft(h)              (uint8_t)(((__GH(h)->Padding >>  0) & 0xFFUL))

#define __GUI_WIDGET_SetPaddingTop(h, x)            (__GH(h)->Padding = (uint32_t)((__GH(h)->Padding & 0x00FFFFFFUL) | (uint32_t)((uint8_t)(x)) << 24))
#define __GUI_WIDGET_SetPaddingRight(h, x)          (__GH(h)->Padding = (uint32_t)((__GH(h)->Padding & 0xFF00FFFFUL) | (uint32_t)((uint8_t)(x)) << 16))
#define __GUI_WIDGET_SetPaddingBottom(h, x)         (__GH(h)->Padding = (uint32_t)((__GH(h)->Padding & 0xFFFF00FFUL) | (uint32_t)((uint8_t)(x)) <<  8))
#define __GUI_WIDGET_SetPaddingLeft(h, x)           (__GH(h)->Padding = (uint32_t)((__GH(h)->Padding & 0xFFFFFF00UL) | (uint32_t)((uint8_t)(x)) <<  0))
#define __GUI_WIDGET_SetPaddingTopBottom(h, x)  do {    \
    __GUI_WIDGET_SetPaddingTop(h, x);                   \
    __GUI_WIDGET_SetPaddingBottom(h, x);                \
} while (0)
#define __GUI_WIDGET_SetPaddingLeftRight(h, x)  do {    \
    __GUI_WIDGET_SetPaddingLeft(h, x);                  \
    __GUI_WIDGET_SetPaddingRight(h, x);                 \
} while (0)
#define __GUI_WIDGET_SetPadding(h, x)  do {             \
    __GUI_WIDGET_SetPaddingTop(h, x);                   \
    __GUI_WIDGET_SetPaddingLeft(h, x);                  \
    __GUI_WIDGET_SetPaddingBottom(h, x);                \
    __GUI_WIDGET_SetPaddingRight(h, x);                 \
} while (0)

#define __GUI_WIDGET_Callback(h, cmd, param, result)    (h)->Callback ? (h)->Callback(h, cmd, param, result) : (h)->Widget->Callback(h, cmd, param, result)

/**
 * \brief           Get total width of widget in units of pixels
 * \note            Since this function is private, it can only be used by user inside GUI library
 *
 * \note            Even if percentage width is used, function will always return value in pixels
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Total width in units of pixels
 * \sa              __GUI_WIDGET_GetInnerWidth
 */
GUI_Dim_t __GUI_WIDGET_GetWidth(GUI_HANDLE_p h);

/**
 * \brief           Get total height of widget
 * \note            Since this function is private, it can only be used by user inside GUI library
 *
 * \note            Even if percentage height is used, function will always return value in pixels
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Total height in units of pixels
 * \sa              __GUI_WIDGET_GetInnerHeight
 * \hideinitializer
 */
GUI_Dim_t __GUI_WIDGET_GetHeight(GUI_HANDLE_p h);

/**
 * \brief           Get inner width (total width - padding left - padding right)
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Height in units of pixels
 * \sa              __GUI_WIDGET_GetInnerHeight
 * \hideinitializer
 */
#define __GUI_WIDGET_GetInnerWidth(h)               (__GUI_WIDGET_GetWidth(h) - (__GUI_WIDGET_GetPaddingLeft(h) + __GUI_WIDGET_GetPaddingRight(h)))

/**
 * \brief           Get inner height (total height - padding top - padding bottom)
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Inner height in units of pixels
 * \sa              __GUI_WIDGET_GetInnerWidth
 * \hideinitializer
 */
#define __GUI_WIDGET_GetInnerHeight(h)              (__GUI_WIDGET_GetHeight(h) - (__GUI_WIDGET_GetPaddingTop(h) + __GUI_WIDGET_GetPaddingBottom(h)))

/**
 * \brief           Returns width of parent element. If parent does not exists, it returns LCD width
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Parent width in units of pixels
 * \sa              __GUI_WIDGET_GetParentHeight
 * \hideinitializer
 */
#define __GUI_WIDGET_GetParentWidth(h)              (__GH(h)->Parent ? __GUI_WIDGET_GetWidth((h)->Parent) : GUI.LCD.Width)

/**
 * \brief           Returns height of parent element. If parent does not exists, it returns LCD height
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          Parent height in units of pixels
 * \sa              __GUI_WIDGET_GetParentWidth
 * \hideinitializer
 */
#define __GUI_WIDGET_GetParentHeight(h)             (__GH(h)->Parent ? __GUI_WIDGET_GetHeight((h)->Parent) : GUI.LCD.Height)

/**
 * \brief           Returns inner width of parent element. If parent does not exists, it returns LCD width
 * \note            Since this function is private, it can only be used by user inside GUI library
 *
 * \note            It returns inner width = total width - padding left - padding right
 * \param[in]       h: Pointer to \ref GUI_HANDLE_p structure
 * \retval          Parent width in units of pixels
 * \sa              __GUI_WIDGET_GetParentInnerHeight
 * \hideinitializer
 */
#define __GUI_WIDGET_GetParentInnerWidth(h)         (__GH(h)->Parent ? __GUI_WIDGET_GetInnerWidth((h)->Parent) : GUI.LCD.Width)

/**
 * \brief           Returns inner height of parent element. If parent does not exists, it returns LCD height
 * \note            Since this function is private, it can only be used by user inside GUI library
 *
 * \note            It returns inner height = total height - padding top - padding bottom
 * \param[in,out]   h: Widget handle
 * \retval          Parent height in units of pixels
 * \sa              __GUI_WIDGET_GetParentInnerWidth
 * \hideinitializer
 */
#define __GUI_WIDGET_GetParentInnerHeight(h)        (__GH(h)->Parent ? __GUI_WIDGET_GetInnerHeight((h)->Parent) : GUI.LCD.Height)

/**
 * \brief           Check if widget is visible
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Widget is visible
 * \retval          0: Widget is not visible
 * \sa              __GUI_WIDGET_IsHidden
 * \hideinitializer
 */
#define __GUI_WIDGET_IsVisible(h)                   (!(__GH(h)->Flags & GUI_FLAG_HIDDEN))

/**
 * \brief           Check if widget is hidden
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Widget is hidden
 * \retval          0: Widget is not hidden
 * \sa              __GUI_WIDGET_IsVisible
 * \hideinitializer
 */
#define __GUI_WIDGET_IsHidden(h)                    (__GH(h)->Flags & GUI_FLAG_HIDDEN)

/**
 * \brief           Check if widget allows children widgets
 * \note            Since this function is private, it can only be used by user inside GUI library
 * \param[in,out]   h: Widget handle
 * \retval          1: Widget allows children widgets
 * \retval          0: Widget does not allow children widgets
 * \hideinitializer
 */
#define __GUI_WIDGET_AllowChildren(h)               (__GH(h)->Widget->MetaData.Flags & GUI_FLAG_WIDGET_ALLOW_CHILDREN)

/**
 * \}
 */
#endif /* defined(GUI_INTERNAL) || defined(DOXYGEN) */

/**
 * \brief           Checks if Widget handle is currently in focus
 * \param[in,out]   h: \ref GUI_HANDLE_p widget
 * \retval          Status whether widget is in focus or not
 * \hideinitializer
 */
#define GUI_WIDGET_IsFocused(h)                     (__GH(h) == GUI.FocusedWidget)

/**
 * \brief           Remove widget from memory
 * \note            If widget has child widgets, they will be removed too
 * \param[in,out]   *h: Pointer to widget handle. If removed, pointer will be invalidated and set to NULL
 * \retval          1: Widget deleted
 * \retval          0: Delete failed
 */
uint8_t GUI_WIDGET_Remove(GUI_HANDLE_p* h);

/**
 * \brief           Allocate memory for text operations if text will be dynamic
 * \note            When unicode feature is enabled, memory should be 4x required characters because unicode can store up to 4 bytes for single character
 * \param[in,out]   h: Widget handle
 * \param[in]       size: Number of bytes to allocate
 * \retval          Number of bytes allocated
 * \sa              GUI_WIDGET_FreeTextMemory
 */
uint32_t GUI_WIDGET_AllocTextMemory(GUI_HANDLE_p h, uint32_t size);

/**
 * \brief           Frees memory previously allocated for text
 * \param[in,out]   h: Widget handle to free memory on
 * \retval          Widget handle
 * \sa              GUI_WIDGET_AllocTextMemory
 */
GUI_HANDLE_p GUI_WIDGET_FreeTextMemory(GUI_HANDLE_p h);

/**
 * \brief           Set text to widget
 * \note            If dynamic memory allocation was used then content will be copied to allocated memory
 *                     otherwise only pointer to input text will be used 
 *                     and each further change of input pointer text will affect to output
 * \param[in,out]   h: Widget handle
 * \param[in]       *text: Pointer to text to set to widget
 * \retval          Widget handle
 * \sa              GUI_WIDGET_AllocTextMemory
 * \sa              GUI_WIDGET_SetFont
 */
GUI_HANDLE_p GUI_WIDGET_SetText(GUI_HANDLE_p h, const GUI_Char* text);

/**
 * \brief           Set widget font for drawing operations
 * \param[in,out]   h: Widget handle
 * \param[in]       *font: Pointer to \ref GUI_FONT_t object for font
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetText
 */
GUI_HANDLE_p GUI_WIDGET_SetFont(GUI_HANDLE_p h, GUI_Const GUI_FONT_t* font);

/**
 * \brief           Set widget size in units of pixels
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Width in units of pixels
 * \param[in]       height: Height in units of pixels
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetXY
 */
GUI_HANDLE_p GUI_WIDGET_SetSize(GUI_HANDLE_p h, GUI_Dim_t width, GUI_Dim_t height);

/**
 * \brief           Set width of widget in units of pixels
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Width in units of pixels
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetWidthPercent
 * \sa              GUI_WIDGET_SetHeightPercent
 */
GUI_HANDLE_p GUI_WIDGET_SetWidth(GUI_HANDLE_p h, GUI_Dim_t width);

/**
 * \brief           Set height of widget in units of pixels
 * \param[in,out]   h: Widget handle
 * \param[in]       height: Height in units of pixels
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetWidthPercent
 * \sa              GUI_WIDGET_SetHeightPercent
 */
GUI_HANDLE_p GUI_WIDGET_SetHeight(GUI_HANDLE_p h, GUI_Dim_t height);

/**
 * \brief           Set width of widget in percentage relative to parent widget
 * \param[in,out]   h: Widget handle
 * \param[in]       width: Width in percentage
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetHeightPercent
 */
GUI_HANDLE_p GUI_WIDGET_SetWidthPercent(GUI_HANDLE_p h, GUI_Dim_t width);

/**
 * \brief           Set height of widget in percentage relative to parent widget
 * \param[in,out]   h: Widget handle
 * \param[in]       height: Height in percentage
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetWidth
 * \sa              GUI_WIDGET_SetHeight
 * \sa              GUI_WIDGET_SetWidthPercent
 */
GUI_HANDLE_p GUI_WIDGET_SetHeightPercent(GUI_HANDLE_p h, GUI_Dim_t height);

/**
 * \brief           Set widget position relative to parent object in units of pixels
 * \param[in,out]   h: Widget handle
 * \param[in]       x: X position relative to parent object
 * \param[in]       y: Y position relative to parent object
 * \retval          Widget handle
 * \sa              GUI_WIDGET_SetSize
 */
GUI_HANDLE_p GUI_WIDGET_SetXY(GUI_HANDLE_p h, GUI_iDim_t x, GUI_iDim_t y);

/**
 * \brief           Show widget from visible area
 * \param[in,out]   h: Widget handle
 * \retval          Widget handle
 * \sa              GUI_WIDGET_Hide
 */
GUI_HANDLE_p GUI_WIDGET_Show(GUI_HANDLE_p h);

/**
 * \brief           Hide widget from visible area
 * \param[in,out]   h: Widget handle
 * \retval          Widget handle
 * \sa              GUI_WIDGET_Show
 */
GUI_HANDLE_p GUI_WIDGET_Hide(GUI_HANDLE_p h);

/**
 * \brief           Invalidate widget object and prepare to new redraw
 * \param[in,out]   h: Widget handle
 * \retval          Widget handle
 */
GUI_HANDLE_p GUI_WIDGET_Invalidate(GUI_HANDLE_p h);

/**
 * \brief           Check if widget is children of parent
 * \param[in]       h: Widget handle to test
 * \param[in]       parent: Parent widget handle to test if is parent
 * \retval          1: Widget handle is in tree of parent handle
 * \retval          0: Widget handle is not in tree of parent handle
 */
uint8_t GUI_WIDGET_IsChildOf(GUI_HANDLE_p h, GUI_HANDLE_p parent);

#if defined(GUI_INTERNAL) && !defined(DOXYGEN)
//Strictly private functions by GUI
//Widget initialization purpose
void __GUI_WIDGET_Init(void);

//Clipping regions
void __GUI_WIDGET_SetClippingRegion(GUI_HANDLE_p h);
uint8_t __GUI_WIDGET_IsInsideClippingRegion(GUI_HANDLE_p h);

//Move widget down and all its parents with it
void __GUI_WIDGET_MoveDownTree(GUI_HANDLE_p h);
#endif /* !defined(DOXYGEN) */

/**
 * \}
 */
 
/**
 * \}
 */

/* C++ detection */
#ifdef __cplusplus
}
#endif

#endif