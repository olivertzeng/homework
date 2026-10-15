# 自我檢測用評分程式

這裡是各作業系統的評分程式,讓你在交件前先自己打分數。**這是練習用的**,
題庫和金鑰都是公開的;老師正式評分時會換一套你拿不到的題庫,所以請不要想著
針對這份題庫作弊——換了題庫就沒用了。

## 選你的作業系統

| 檔案 | 平台 |
| --- | --- |
| `judge-windows-amd64.exe` | Windows (x64) |
| `judge-linux-amd64` | Linux (x64) |
| `judge-linux-arm64` | Linux (ARM64) |
| `judge-macos-amd64` | macOS (Intel) |
| `judge-macos-arm64` | macOS (Apple Silicon) |

評分程式會呼叫 `gcc` 來編譯你的作業,所以**你的電腦要先裝好 gcc**(Windows 可用
MinGW/MSYS2,macOS 可用 Xcode Command Line Tools,Linux 直接裝 build-essential)。

## 怎麼用

練習金鑰(公開):

```
practice-key-2026-public-do-not-use-for-real-grading
```

Linux / macOS(把下面的執行檔換成你的平台,第一次要先 `chmod +x`):

```bash
export HW_JUDGE_KEY='practice-key-2026-public-do-not-use-for-real-grading'
./judge-linux-amd64 grade -sub .. -json report.json
```

Windows(PowerShell):

```bash
$env:HW_JUDGE_KEY='practice-key-2026-public-do-not-use-for-real-grading'
.\judge-windows-amd64.exe grade -sub .. -json report.json
```

`-sub ..` 指向上一層的作業資料夾(也就是放 `a.c`、`b.c` 的那層)。

常用參數:

- `-skip-search`:只跑第一部分(引擎正確性檢查),不跑那支很慢的解密程式,想快速檢查時用。
- `-timeout 60m`、`-total-timeout 60m`:單題與整份的時間上限(預設都是 60 分鐘,和正式評分相同);
  還沒優化的版本會逾時,這是正常的。
- `grade -h`:印出輸出與建置的格式約定(你的程式要印哪幾行、`judge_build.txt` 怎麼寫)。

## 評分方式(和正式評分相同)

**總分 100 = 破解正確率 10 分 + 速度分 90 分**:

- **正確率 A**:隱藏密文中,你印出的 `text:` 明文完全正確的比例,佔 10 分。
- **速度分 S = 100 × A⁷ ÷ (1 + (T/C)^1.5)**,佔 90 分。T/C 是你的程式「單執行緒 CPU 時間 ÷ 同一台
  機器上的通用 CPU 基準時間」再除以 `uref`(預設 `0.0012`),所以跟電腦快慢無關。
  準確率不夠時速度分會大打折扣(A 的 7 次方)。
- 對照(全部解對時):T/C = 2 → 總分約 33.5;T/C = 1 → 55;T/C = 0.5 → 約 76.5。
- 評分時會設 `HW_JUDGE_THREADS=1`、用單執行緒計 CPU 時間,開多執行緒不會讓分數變高。
- 第一部分(引擎的內建測試、參數處理、隨機設定)只做檢查、不計分;不過引擎錯了,解密也會跟著錯。

`judge_build.txt` 已經幫你把來源檔指好了(`b.c` 當引擎、`a.c` 當解密器)。如果你把程式
拆成更多檔案或需要額外編譯參數,就改這個檔。
