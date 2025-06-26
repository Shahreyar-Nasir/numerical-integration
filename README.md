# 📊 Numerical Integration Methods in C

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" />
  <img src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg" />
</p>

Welcome to a practical and modular implementation of **Numerical Integration techniques** using **C**!  
This repository covers various approximation methods to compute definite integrals of real-valued functions where analytical integration is hard or inefficient.


---

## 🧠 Why Numerical Integration?

> Not all functions have antiderivatives that can be expressed in closed-form. That’s where numerical integration shines.

It is used when:
- The function is defined by a table of values or is discontinuous
- The integral has no closed-form
- High-speed approximation is needed (e.g., simulations)

---

## ✅ Implemented Methods

| File                      | Method                    | Strengths |
|---------------------------|---------------------------|-----------|
| `Trapezoidal.c`           | Trapezoidal Rule          | Fast, simple, decent for smooth functions |
| `Simpsons_one_third.c`    | Simpson's 1/3 Rule        | Very accurate, uses parabolic approximation |
| `Simpsons_three_eights.c` | Simpson's 3/8 Rule        | Similar to 1/3 but better for non-even intervals |
| `Romberg.c`               | Romberg Integration       | Extrapolates for better accuracy with fewer evaluations |
| `Gauss_Legendere.c`       | Gauss-Legendre Quadrature| High precision, optimal node placement |

---

## 📌 Use Cases

- 🚀 Physics simulations (e.g., area under velocity-time graphs)
- 📈 Engineering applications (stress, strain, and loading)
- 🧪 Chemistry and thermodynamics
- 🧮 Solving ODEs using numerical methods
- 🎮 Game physics and procedural modeling

---

 **Clone the Repository**
   ```bash
   git clone https://github.com/Shahreyar-Nasir/numerical-integration.git
   cd numerical-integration

