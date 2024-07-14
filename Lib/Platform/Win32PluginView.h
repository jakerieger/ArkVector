// Author: Jake Rieger
// Created: 7/11/2024.
//

#pragma once

#include "Platform.h"
#include "Interfaces/PluginView.h"

namespace ArkVector {
    class Win32PluginView final : public IPluginView {
    public:
        explicit Win32PluginView(const Size<u32>& windowSize) : IPluginView(windowSize) {}

        void Initialize(HWND parent, int nCmdShow);
        void Shutdown() override;
        void OnResize(const Size<u32>& newSize) override;

        static LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    private:
        HWND m_Handle        = nullptr;
        HINSTANCE m_Instance = nullptr;
    };
}  // namespace ArkVector