// Author: Jake Rieger
// Created: 7/11/2024.
//

#pragma once

#include "Platform.h"
#include "Interfaces/PluginView.h"

namespace Fuse {
    class Win32PluginView final : public IPluginView {
    public:
        explicit Win32PluginView(HWND parent) : IPluginView(parent) {}

        // TODO: parent isn't needed as an arg, can be accessed via this->m_Parent as void ptr
        void Initialize(HWND parent, int nCmdShow);
        void Shutdown() override;
        void OnResize(const Size<u32>& newSize) override;

        HWND GetHandle() const {
            return m_Handle;
        }

        static LRESULT CALLBACK MessageHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

        void OnMouseMove(int x, int y) override;

    private:
        HWND m_Handle        = nullptr;
        HINSTANCE m_Instance = nullptr;
    };
}  // namespace Fuse