# Catalog Placements Assignment – Shamir's Secret Sharing (SSSA)

## 📌 Problem Statement

This project implements a simplified version of **Shamir’s Secret Sharing Algorithm**. You are given `n` encoded (x, y) roots of an unknown polynomial of degree `m`, and you must:

- Decode the values provided in various number bases
- Identify the **correct subset of `k = m + 1` valid points** (some points may be incorrect)
- Use **Lagrange Interpolation** to reconstruct the secret constant term `c` of the polynomial

---

## 🔍 Input Format

Each test case is stored in a separate JSON file:

```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": {
    "base": "10",
    "value": "4"
  },
  "2": {
    "base": "2",
    "value": "111"
  },
  ...
}
```

- `n`: Total number of (x, y) points provided
- `k`: Number of correct points required to solve (k = degree + 1)
- The object keys (`"1"`, `"2"`, etc.) represent the x-values
- Each value is a pair:
  - `base`: the base in which y-value is encoded
  - `value`: the y-value encoded in that base

---

## ⚙️ Features

- Parses input JSON and decodes all values into base-10
- Validates roots by trying all `k`-combinations and checking which value of `c` appears most frequently
- Implements **Lagrange Interpolation** over real numbers
- Supports arbitrarily large encoded inputs (within `long double` range)

---

## 🧪 Sample Output

```bash
Secret from test1.json: 1
Secret from test2.json: 449034238698211034949799
```

---

## 🛠️ How to Compile & Run

1. Make sure you have a C++ compiler (`g++`, `clang++`, etc.)
2. Download [nlohmann/json](https://github.com/nlohmann/json/releases) and place `json.hpp` in the same folder
3. Build and run:

```bash
g++ main.cpp -o sssa
./sssa
```

---

## 📁 Files

| File         | Purpose                                                                |
| ------------ | ---------------------------------------------------------------------- |
| `main.cpp`   | Main program with decoding + interpolation logic                       |
| `test1.json` | Sample test case 1 (k = 3)                                             |
| `test2.json` | Sample test case 2 (k = 7)                                             |
| `json.hpp`   | [nlohmann/json](https://github.com/nlohmann/json) single-header parser |

---

## 🧠 Algorithm Used

- **Lagrange Interpolation** to reconstruct `f(0)` from any `k` valid points
- Brute-force combination check to identify **the most consistent root set**
- Frequency map to find the **most likely secret**

---

## 📝 License

MIT License. Provided as part of the Catalog Placements assignment.

---

## 🙋 Author

**Jitendra Singh**  
4th Year B.Tech CSE  
Catalog Placements Assignment 2025
