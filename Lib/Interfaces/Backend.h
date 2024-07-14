// Author: Jake Rieger
// Created: 7/11/24.
//

#pragma once

#include "Size.h"

namespace ArkVector {
    class IBackend {
    public:
        virtual ~IBackend() = default;
        virtual void Init() {}
        virtual void OnResize(const Size<u32>& size) = 0;
        virtual void OnPaint(const Size<u32>& size)  = 0;

        template<typename T>
        T* As() {
            static_assert(std::is_base_of_v<IBackend, T>, "T must implement IBackend");
            return dynamic_cast<T*>(this);
        }

        virtual void DrawRect() {}
        virtual void DrawLine() {}
        virtual void DrawEllipse() {}
        virtual void DrawPath() {}
        virtual void DrawString() {}

    protected:
        virtual void Shutdown() = 0;
    };
}  // namespace ArkVector