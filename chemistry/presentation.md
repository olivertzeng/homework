<style>
  .title-top {
    position: absolute;
    top: 0;
    left: 0;
    right: 0;
    text-align: center;
    margin-top: 10px;
  }
</style>

## 雙氧水分解對pH值影響
### 1626 第六組
<font color="#adadad"> **曾嘉禾 程至恆 黃宥程 黃少鈞** </font>

---

### 假說

ph值會因為雙氧水的分解而下降

---

### 實驗流程圖
mermaid
graph TD;
準備器材、材料-->製備對照組;
製備對照組-->開始實驗以準備實驗組;
開始實驗以準備實驗組-->比較實驗組以及對照組;
比較實驗組以及對照組-->驗證假說做出結論;

---

### 實驗組員照片
![image](https://i.imgur.com/y1q9zJ3.jpeg)
![image](https://i.imgur.com/X1cNfPu.jpeg)
![image](https://i.imgur.com/moR8A6W.jpeg)

---

## 結果數據表格

| 實驗次數  | 實驗組             | 對照組  |
|----------|-------------------|--------|
| 1        | 6.3               | 3.3    |
| 2        | 6.3               | 3.3    |
| 3        | 6.4               | 3.3    |
| 4        | 6.4               | 3.3    |
| 5        | 6.9               | 3.3    |
| 平均      | 6.46              | 3.3    |
| SD       | 0.25              | 0      |

---

```vega


{
  "$schema": "https://vega.github.io/schema/vega-lite/v5.json",
  "title": {
    "text": "平均 pH 值",
    "fontSize": 55
  },
  "data": {
    "values": [
      { "組別": "實驗組", "pH 值": 6.46, "stddev": 0.250998007960223 },
      { "組別": "對照組", "pH 值": 3.3, "stddev": 0 }
    ]
  },
  "layer": [
    {
      "mark": { "type": "bar", "width": { "band": 0.4 }, "cornerRadiusEnd": 20 },
      "encoding": {
        "x": {
          "field": "組別",
          "type": "nominal",
          "axis": { "labelAngle": 0, "labelFontSize": 20, "titleFontSize": 30 }
        },
        "y": {
          "field": "pH 值",
          "type": "quantitative",
          "axis": {
            "titlePadding": 50,
            "titleAngle": 0,
            "labelFontSize": 20,
            "titleFontSize": 30
          }
        }
      }
    },
    {
      "mark": "rule",
      "encoding": {
        "x": {
          "field": "組別",
          "type": "nominal"
        },
        "y": {
          "field": "pH 值",
          "type": "quantitative"
        },
        "y2": {
          "field": "pH 值",
          "type": "quantitative"
        },
        "color": {
          "value": "green"
        },
        "strokeWidth": {
          "value": 20
        }
      }
    },
    {
      "mark": "rule",
      "encoding": {
        "x": {
          "field": "組別",
          "type": "nominal"
        },
        "x2": {
          "field": "組別",
          "type": "nominal"
        },
        "y": {
          "field": "pH 值",
          "type": "quantitative"
        },
        "y2": {
          "field": "pH 值",
          "type": "quantitative"
        },
        "color": {
          "value": "lime"
        },
        "strokeWidth": {
          "value": 20
        }
      }
    },
    {
      "mark": "errorbar",
      "encoding": {
        "x": {
          "field": "組別",
          "type": "nominal"
        },
        "y": {
          "field": "pH 值",
          "type": "quantitative"
        },
        "yError": {
          "field": "stddev"
        },
        "color": {
          "value": "lime"
        },
        "strokeWidth": {
          "value": 20
        }
      }
    }
  ],
  "height": 400,
  "width": 600
}

```

---

## 結論
<br>
pH值會因為
