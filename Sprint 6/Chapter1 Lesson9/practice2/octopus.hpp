#pragma once

#include "scopedptr.hpp"
#include "ptrvector.hpp"

#include <new>
#include <vector>

class Tentacle {
public:
    
    explicit Tentacle (int id) noexcept : id_(id)
    {   
    }

    int GetId() const noexcept {
        return id_;
    }

    Tentacle* GetLinkedTentacle() const noexcept {
        return linked_tentacle_;
    }

    void LinkTo(Tentacle& tentacle) noexcept {
        linked_tentacle_ = &tentacle;
    }

    void Unlink() noexcept {
        linked_tentacle_ = nullptr;
    }

private:
    int id_ = 0;
    Tentacle* linked_tentacle_ = nullptr;
};

class Octopus {
public:
    Octopus()
        : Octopus(8) {
    }

    explicit Octopus(int num_tentacles) {
        Tentacle* t = nullptr;
        try {
            for (int i = 1; i <= num_tentacles; ++i) {
                t = new Tentacle(i);      
                tentacles_.GetItems().push_back(t);  
                t = nullptr;
            }
        }
        catch (const std::bad_alloc&) {
            Cleanup();
            delete t;
            throw;
        }
    }

    ~Octopus() {
        Cleanup();
    }

    Tentacle& AddTentacle() {
        tentacles_.GetItems().push_back(new Tentacle(static_cast<int>(tentacles_.GetItems().size()) + 1));
        return *tentacles_.GetItems().back();

    }

    int GetTentacleCount() const noexcept {
        return static_cast<int>(tentacles_.GetItems().size());
    }

    const Tentacle& GetTentacle(size_t index) const {
        return *tentacles_.GetItems().at(index);
    }
    Tentacle& GetTentacle(size_t index) {
        return *tentacles_.GetItems().at(index);
    }


private:
    void Cleanup() {
        for (Tentacle* t : tentacles_.GetItems()) {
            delete t;
        }
        tentacles_.GetItems().clear();
    }
    PtrVector<Tentacle> tentacles_;
};