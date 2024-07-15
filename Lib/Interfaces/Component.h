// Author: Jake Rieger
// Created: 7/12/2024.
//

#pragma once

#include "Traits.h"

namespace ArkVector {
    class IBackend;

    class IComponent {
    public:
        virtual ~IComponent() = default;

        virtual void Draw(IBackend* backend) = 0;

        bool HasChild() {
            const auto thisPtr = dynamic_cast<Traits::TSingleChild*>(this);
            return thisPtr != nullptr;
        }

        bool HasChildren() {
            const auto thisPtr = dynamic_cast<Traits::TMultiChild*>(this);
            return thisPtr != nullptr;
        }

        IComponent* GetChild() {
            if (HasChild()) {
                const auto thisPtr = dynamic_cast<Traits::TSingleChild*>(this);
                return thisPtr->m_Child;
            }

            return nullptr;
        }

        std::vector<IComponent*>& GetChildren() {
            if (HasChildren()) {
                const auto thisPtr = dynamic_cast<Traits::TMultiChild*>(this);
                return thisPtr->m_Children;
            }
        }
    };
}  // namespace ArkVector