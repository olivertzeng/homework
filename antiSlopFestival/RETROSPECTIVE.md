1. AI used
Sources:
- Antigravity([gcli2api](https://github.com/su-kaka/gcli2api))
- AI Studio([AIStudioToAPI](https://github.com/iBUHub/AIStudioToAPI))
Models:
- Gemini 3.1 Pro
- Claude 4.6 Sonnet/Opus
- Gemini 3.8 Flash
Prompt used:
- [benriwuBeilu 便利屋 Beilu](https://raw.githubusercontent.com/olivertzeng/dotfiles/refs/heads/main/benriwuBeilu.md): Traditional Chinese prompt that was edited and refined from Beilu's prompt from China, has custom CoT and jailbreak(not mainly for jailbreaks, but it can)

2. What AI does the best
- Teaching me about how CSS, HTML, and TS/JS work and interact with each other
- Making me deduct and realize how website works without being given an answer directly

AI:
> ```css
> /* 當月餅被點擊(按下)時的狀態 */
> #moonCakeBtn:active {
>     transform: scale(0.9); /* 點下去時縮小 10% */
> }
> ```
> ...
> 讓對話框背後的遮罩變暗
（Dialog 有一個特殊的偽元素 ::backdrop，專門控制它背後那層）

User:

> 為什麼dialog 是兩個冒號之後才是backdrop，而button是一個？
還是我在猜可能是
名詞:形容詞（狀態）
名詞::名詞（形容物體特性）

AI:
> 你對單冒號與雙冒號的推論：100% 正確！
> 你猜的「名詞:狀態」和「名詞::虛擬物體」，**就是 CSS 官方的設計邏輯！** 你太強了。
> - **單冒號 `:` (Pseudo-class 偽類)**：代表這個東西的**「狀態」**。
  例如 `button:hover`（滑鼠懸停時）、`button:active`（按下去的那一刻）。東西還是那個按鈕，只是狀態變了。
> - **雙冒號 `::` (Pseudo-element 偽元素)**：代表你憑空創造了一個原本在 HTML 裡**不存在的部位**。
  例如 `dialog::backdrop`，你在控制的是「對話框背後的那片陰影」。那片陰影在 HTML 標籤裡是不存在的，是瀏覽器長出來的，所以用兩個冒號。

3. What AI ruined the most
- None? Most of the time it's being a good teacher, except sometimes if you don't explicitly mention about the willingness of coding by hand it will accidentally code for you.(for a lot of people it might not be the worst thing, but I certainly don't want that)

4. How I realized AI's error
- Continuing 3 since there aren't actual grave errors(only from humans, me), fortunantly I can keep hallutionations to my own brain

5. How I finally solved the problem(provided by the context of 3)
- Edit the prompt to explicitly mention I do not want to be fed with answers
User:
> the reason why i kinda dislike SPEC.md because it sounds like a step to vibecoding, not because i hate writing docs
in fact, I LOVE making pull requests to rehandwrite a badly ai written README.md and then refactor it by an AI to make it more readable
also im kinda stuck writing SPEC.md here because although i can kinda write css ts and html, i still don't really understand how to piece them together since a lot of stuff is probably more than just buttons and clicks
i think i will try and then actually implement in html myself
Structure of project
html structure
**also please please please do not help me write any code, just give me tips unless i ask you to help**

6. If I were to redo this how I would change my ways of cooporating with AI
- None, AI sometimes might teach better than humans, but after all, learning coding by hand is more important and way more exciting than anything.
