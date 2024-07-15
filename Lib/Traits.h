// Author: Jake Rieger
// Created: 7/12/2024.
//

#pragma once

#include <vector>

namespace ArkVector {
    // Forward declaration
    class IComponent;
}  // namespace ArkVector

namespace ArkVector::Traits {
    class TSingleChild {
    public:
        IComponent* m_Child = nullptr;
    };

    class TMultiChild {
    public:
        std::vector<IComponent*> m_Children = {};
    };

    class TNotify {};
}  // namespace ArkVector::Traits