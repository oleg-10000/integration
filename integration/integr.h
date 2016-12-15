#pragma once
#include <vector>
#include <functional>
#include <stdexcept>
namespace integration
{
	template <class T>
	using v_t = std::vector<T>;
	template<class T>
	using F_t = std::function<T(T t0, const v_t<T>& x0)>;
	template<class T>
	using vF_t = v_t<F_t<T>>;
	template<class T>
	using method_t = std::function<v_t<T>(const vF_t<T> &F, const v_t<T>& x0, T t0, T h)>;

	template<class T>
	v_t<T> Cauchy(const vF_t<T>& F, const v_t<T>& x0
		, const T t0, const T tk, const T h, const method_t<T>& method
		, const std::function<void(T ti, const v_t<T>& xi)>& D)
	{
		const size_t n = F.size();
		if (n != x0.size()) throw std::invalid_argument("Количество значений в массивах не совпадает");
		
		v_t<T> x = x0;
		T t = t0;
		for (T ti = t0; ti < tk; ti += h)
		{
			t = ti;
			x = method(F, x, t, h);
			D(t, x);
		}
		x = method(F, x, tk, tk-t);
		D(tk, x);
		return x;
	}

	template<class T>
	v_t<T> EulerMethod(const vF_t<T> &F, const v_t<T>& x0, const T t0, const T h)//Метод Эйлера
	{
		const size_t n = x0.size();
		v_t<T> x(n);
		for (size_t i = 0; i < n; ++i)
		{
			x[i] = x0[i] + h*F[i](t0, x0);
		}
		return x;
	}

	template<class T>
	v_t<T> RungeKuttaMethod(const vF_t<T> &F, const v_t<T>& x0, const T t0, const T h)//Метод Рунге — Кутты
	{
		const size_t n = x0.size();
		
		auto L = [n, &x0](const T m, v_t<T> k)//x0+m*k
		{
			for (size_t i = 0; i < n; i++)
				k[i] = x0[i] + m*k[i];
			return k;
		};

		v_t<T> k1(n);
		for (size_t i = 0; i < n; ++i)
			k1[i] = F[i](t0, x0);
		v_t<T> k2(n);
		for (size_t i = 0; i < n; ++i)
			k2[i] = F[i](t0+h/2, L(h/2.0, k1));//F[i](t0+h/2, x0+h/2*k1)
		v_t<T> k3(n);
		for (size_t i = 0; i < n; ++i)
			k3[i] = F[i](t0+h/2, L(h/2.0, k2));//F[i](t0+h/2, x0+h/2*k2)
		v_t<T> k4(n);
		for (size_t i = 0; i < n; ++i)
			k4[i] = F[i](t0 + h, L(h, k3));//F[i](t0+h, x0+h*k3)
		v_t<T> x(n);
		for (size_t i = 0; i < n; ++i)
			x[i] = x0[i] + h / 6.0*(k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
		return x;
	}
}
	{
		const size_t n = x0.size();
		
		auto L = [n, &x0](const T m, v_t<T> k)//x0+m*k
		{
			for (size_t i = 0; i < n; i++)
				k[i] = x0[i] + m*k[i];
			return k;
		};

		v_t<T> k1(n);
		for (size_t i = 0; i < n; ++i)
			k1[i] = F[i](t0, x0);
		v_t<T> k2(n);
		for (size_t i = 0; i < n; ++i)
			k2[i] = F[i](t0+h/2, L(h/2.0, k1));//F[i](t0+h/2, x0+h/2*k1)
		v_t<T> k3(n);
		for (size_t i = 0; i < n; ++i)
			k3[i] = F[i](t0+h/2, L(h/2.0, k2));//F[i](t0+h/2, x0+h/2*k2)
		v_t<T> k4(n);
		for (size_t i = 0; i < n; ++i)
			k4[i] = F[i](t0 + h, L(h, k3));//F[i](t0+h, x0+h*k3)
		v_t<T> x(n);
		for (size_t i = 0; i < n; ++i)
			x[i] = x0[i] + h / 6.0*(k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]);
		return x;
	}
}
