
/*

    Plutonium library

    @file Element.hpp
    @brief An Element is the base of Plutonium UI's content.
    @author XorTroll

    @copyright Plutonium project - an easy-to-use UI framework for Nintendo Switch homebrew

*/

#pragma once
#include <pu/types.h>
#include <pu/pu_Macros.hpp>
#include <pu/ui/render/render_Renderer.hpp>
#include <SDL2/SDL.h>

namespace pu::ui::elm
{
    enum class HorizontalAlign
    {
        Left,
        Center,
        Right,
    };

    enum class VerticalAlign
    {
        Up,
        Center,
        Down,
    };

    class Element
    {
        public:
            Element();
            PU_SMART_CTOR(Element)
            virtual ~Element();

            // In order to make custom UI Elements, need to implement this functions
            virtual i32 GetX() = 0;
            virtual i32 GetY() = 0;
            virtual i32 GetWidth() = 0;
            virtual i32 GetHeight() = 0;
            virtual void OnRender(render::Renderer::Ref &Drawer, i32 X, i32 Y) = 0;
            virtual void OnInput(SDL_Event&) = 0;

            bool IsVisible();
            void SetVisible(bool Visible);
            void SetParent(void *Base);
            void *GetParent();
            void SetHorizontalAlign(HorizontalAlign Align);
            HorizontalAlign GetHorizontalAlign();
            void SetVerticalAlign(VerticalAlign Align);
            VerticalAlign GetVerticalAlign();
            bool HasParent();
            i32 GetProcessedX();
            i32 GetProcessedY();
        protected:
            bool visible;
            HorizontalAlign halign;
            VerticalAlign valign;
            void *parent;
    };
}
