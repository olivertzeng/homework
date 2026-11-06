# SOLID

SRP: Single Responsibility Principle
One thing per class(Subjective)
no class Cat():
but
class catWalk class catEat class catDrink()

OCP: Open/Cloased Principle
Open to extensions closed to modifications
Constitution law 憲法修正條例

LSP: Liskov Substitution Principle
Backwards Compatibility

ISP: Interface Segregation Principle
No interface for all

DIP: Dependency Inversion Principle
# ❌
install_packages() {
    apt install git
    apt install vim
}

# ✅
install_packages() {
    $PKG_MANAGER install git     # ← 依賴一個「抽象」
    $PKG_MANAGER install vim
}

---

Encapsulate What Varies
Disguise B depends on your weapon slot
Dynamic

Favor Composition Over Inheritance
Composition = A lot of components to be *used*
Inheritance = Forced to lock into a relationship
# 能力是「零件」，自由裝卸

class CanFly:
    def fly(self): ...

class CanSwim:
    def swim(self): ...

class Eagle:
    abilities = [CanFly()]

class Penguin:
    abilities = [CanSwim()]

class FlyingFish:
    abilities = [CanFly(), CanSwim()]

Least Knowledge Principle
Docker volume

ADP: Acyclic Dependencies Principle
A needs B;B needs C;C needs A

DRY: Don't Repeat Yourself
Don't Repeat Yourself(which i just did)
ln -sf ~/dotfiles/yt-dlp ~/.config/yt-dlp/config

KISS: Keep It Simple, Stupid
title
Arch Linux
