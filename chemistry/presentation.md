# 第六組報告

---

# 結果數據表格
| 實驗次數 | 實驗組            | 對照組 |
|----------|-------------------|--------|
| 1        | 6.3               | 3.3    |
| 2        | 6.3               | 3.3    |
| 3        | 6.4               | 3.3    |
| 4        | 6.4               | 3.3    |
| 5        | 6.9               | 3.3    |
| 平均     | 6.46              | 3.3    |
| SD       | 0.25 | 0      |

---

```vega
{
	"$schema": "https://vega.github.io/schema/vega-lite/v5.json",
	"title": {
		"text": "平均 pH 值",
		"fontSize": 75
	},
	"data": {
		"values": [
			{ "組別": "實驗組", "pH 值": 6.46 },
			{ "組別": "對照組", "pH 值": 3.3 }
		]
	},
	"mark": "bar",
	"encoding": {
		"x": {
			"field": "組別",
			"type": "nominal",
			"scale": { "type": "point", "padding": 1 },
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
	},
	"height": 400,
	"width": 600
}
```
