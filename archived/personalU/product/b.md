# 從 Wiki 到 Winning：英文基礎的培養與成果

## 課程連結

這份報告整理了我在課外透過技術社群與日常使用累積的英語能力，以及如何與「英文閱讀與寫作」的課堂內容相互印證。

## 學習背景

我的英語能力並非來自刻意的考試準備，而是在技術學習與日常娛樂中自然累積的。從國二開始瀏覽 Reddit 論壇起，英文就成為我取得資訊的主要語言。從技術類內容、動漫討論，到 Twitter 上的各種社群互動，這種「不是在學英文，而是剛好都在用英文」的狀態，讓語言能力在不知不覺中持續成長。

## 技術場景中的英語沉浸

在從零安裝 Arch Linux 的過程中，我必須逐字閱讀 Arch Wiki 的全英文安裝指南或是看英文教學影片。在讀不懂就裝不起來、沒有中文版可以退的壓力下，久了自然就習慣直接讀原文而不是等翻譯。

## 日常生活中的英語輸入

Reddit 是我國中以來每天都會瀏覽的論壇，從 r/jailbreak 的技術討論到動漫、遊戲相關的 subreddit 如 r/BocchiTheRock，大量英文閱讀就這樣混進了日常生活裡。Twitter 上追蹤的藝術家跟政治與國際新聞也是持續的英語輸入來源。這些看起來不算學習的行為，累積起來對詞彙量與語感的影響非常大。

## 開源協作中學到的跨國溝通

我在 GitHub 上大約有 150 個 pull request 被合併，涵蓋英翻中翻譯、功能開發與各種 bug fixes。這些提交很多都必須用英文與來自不同國家的維護者溝通。

### 用 git submodule 簡化重複流程

在為 wallpaper-cava 這個 Rust 專案貢獻時，我注意到原本的 build 步驟要求使用者手動 clone 兩次 repo，一次是主專案，一次是依賴的 wayland-rs。我提交了一個 PR 用 git submodule 取代手動 clone，讓使用者只需要 `git clone --recursive` 一行就能完成所有準備。維護者與我在六則留言的對話後合併了這個修改，讓我發現效率的重要性不亞於功能性。

### 跨國 code review 中的規範學習

向 nvim-web-devicons 提交檔案類型圖示支援時，因為範圍太大且自行標記 review comment 為已解決，加上未遵守命名規範，被三位 reviewer 反覆要求修改。最後維護者在合併時給出了三條建議避免重蹈覆轍。這次經驗讓我徹底理解「atomic PR」與「尊重 reviewer 流程」的基本紀律。

### 跨環境相容性的實戰經驗

向 iOS 越獄插件 flora 提交修正 shell 顏色輸出的 PR 時，沒有考慮到 sh 與 bash 對 echo -e 的行為差異，導致修正在 Debian 環境下反而產生錯誤。維護者合併後親自補上了相容寫法，我在後續討論中追查了 sh、bash、zsh 三種環境的實際行為差異。這是我第一次意識到「works on my machine」帶來的缺點。

### 從翻譯到架構建議

為系統更新工具 topgrade 提交繁體中文翻譯時，我主動建議維護者將 i18n 架構從單一 YAML 改為 po/mo 分檔。建議最終未被採納，但維護者清楚解釋了集中管理在他們專案脈絡下的優勢。所有的技術決策都必須放回它所處的脈絡中才有意義。

### 回顧

從連 commit 都會打錯、被修正協作規範，到能主動提出架構建議，每一次 PR 學到的不只是英文，更是跨國協作的重要技能。

## 成果驗證

TOEIC Listening & Reading 960 分。在沒有額外準備的狀況下拿到這個成績，驗證了長期處在英語環境對聽力與閱讀的實際效果。

（此處插入：TOEIC 960 成績單截圖）

## 課堂與課外的連結

「英文閱讀與寫作」這堂課給了系統性的語言框架，強化了我在學術文本方面的閱讀策略與結構化寫作能力。課外則提供了大量真實的應用場景跟溝通壓力，兩者互補讓英文實力建立在真正的實用性上。

## 反思

英語對我來說不是一個要特別「學」的科目，而是每天都在用的工具。從逛 Reddit 到寫 PR、從讀 Arch Wiki 到解釋 iOS tweaks，這些事情本身就是無意識的語言訓練。總結這段經歷，想把語言學好，最快的方法就是把自己丟進沒辦法依賴中文的環境裡。

## 附錄

### 代表性 Pull Request 連結

1. rs-pro0/wallpaper-cava #6（用 submodule 簡化 build 流程）
   <https://github.com/rs-pro0/wallpaper-cava/pull/6>

2. acquitelol/flora #5（Shell 顏色輸出修正）
   <https://github.com/acquitelol/flora/pull/5>

3. nvim-tree/nvim-web-devicons #422（檔案類型圖示支援）
   <https://github.com/nvim-tree/nvim-web-devicons/pull/422>

4. topgrade-rs/topgrade #931（英翻中）
   <https://github.com/topgrade-rs/topgrade/pull/931>
