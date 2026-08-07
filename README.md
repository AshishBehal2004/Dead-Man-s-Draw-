<p align="center">
  <img width="649" height="363" alt="Screenshot 2026-08-07 at 3 38 04 pm" src="https://github.com/user-attachments/assets/594b4ea3-e6d4-4973-b972-9b64d5e61178" />
</p>

# Dead Man's Draw++

A command-line, 2-player pirate card game written in C++, built for COMP1039 (Design Patterns with C++). Draw cards, push your luck, and don't draw the same suit twice in one turn.

## How the game works

Two players share one deck of pirate-themed cards. On your turn, you draw cards one at a time and place them in your **Play Area**:

- Every card has a **suit** (Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken) and a **point value**.
- If you draw a suit you already have in your Play Area this turn, you **bust** which means that everything in your Play Area is lost to the Discard Pile, and your turn ends immediately.
- If you stop before busting, everything in your Play Area moves into your **Bank** keeping your cards safe alomg with having permanent points.
- Most suits also trigger a **special ability** the instant they're drawn (see the table below).

The game ends after a fixed number of turns or when the deck runs out. Whoever has the higher score wins.

## Scoring

Your score is the **highest-value card in each suit** you've banked, added together, not every card, just the best one per suit. So banking three Hooks only counts the best Hook once.

## Card abilities

| Suit | What it does |
|---|---|
| Cannon | Discards the other player's best card of any suit from their Bank. |
| Chest | Does nothing on its own, but if you bank a Chest *and* a Key together, you draw bonus cards from the Discard Pile. |
| Key | Same as Chest: the pair triggers together. |
| Sword | Steals the other player's best card of any suit from their Bank straight into your Play Area. |
| Hook | Pulls your own best card of any suit from your Bank into your Play Area. |
| Oracle | Lets you peek at the top card of the deck before deciding whether to draw it. |
| Map | Draws 3 cards from the Discard Pile in which you must play one of them into your Play Area. |
| Mermaid | No special ability, but worth more points than any other suit. |
| Kraken | Forces you to draw and play three cards in a row. |

## Classes

- **`Game`**: runs the whole game: builds and shuffles the deck, sets up both players, and drives the turn loop (draw a card, ask to draw again, switch players on a bust, print final scores).
- **`Player`**: owns one player's Play Area and Bank, checks whether they've busted, and
- **`Card`**: an abstract base class that all 9 suits inherit from. Each suit overrides `play()` to define what happens when it's drawn, and `str()` to print itself (e.g. `"Oracle(7)"`). Chest and Key
also override `willAddToBank()`, since their ability only fires when they're *banked*, no

Keeping each suit's behaviour inside its own class (rather than one big `if/else` in `Gamt later wouldn't require touching the game loop at all.

## Project structure

```
Card.h/.cpp                    # abstract base class for all cards
Cannon.h/.cpp                  # each suit is its own Card subclass...
Chest.h/.cpp
Key.h/.cpp
Sword.h/.cpp
Hook.h/.cpp
Oracle.h/.cpp
Map.h/.cpp
Mermaid.h/.cpp
Kraken.h/.cpp
Player.h/.cpp                  # a player's Bank, Play Area, and score
Game.h/.cpp                    # deck, turn loop, win condition
Dead-Man's-Draw++.cpp          # entry point
```

## Getting started

Built with **Visual Studio 2022**, C++ standard library only, I did not used any external dependencies.

1. Clone the repo and open `Dead-Man's-Draw++.sln` in Visual Studio 2022.
2. Build and run (`F5`).

## Example turn

```
--- Round 1, Turn 1 ---
Sasha's turn.
Sasha's Bank:
 | Score: 0
Sasha draws a Mermaid(5)
 No effect but Mermaids are worth more.
Sasha's Play Area:
 Mermaid(5)

Draw again? (y/n): y
Sasha draws a Key(3)
 No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.
Sasha's Play Area:
 Key(3)
 Mermaid(5)

Draw again? (y/n): y
Sasha draws a Key(7)
BUST! Sasha loses all cards in play area.
```

## Tech

C++, STL containers (`std::vector`, `std::unordered_set`, `std::map`) for collections, dynamically allocated `Card`/`Player` objects, no external libraries.      
