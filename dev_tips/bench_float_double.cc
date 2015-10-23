#include <iostream>
#include <cstdio>
#include <cmath>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) 
  #include <time.h>
  struct __bench__ {
    clock_t start;
     __bench__() { start = clock(); }
    ~__bench__() { printf("%.2lf\n", (double)(clock() - start)/CLOCKS_PER_SEC); }
    operator bool() { return false; }
  };
#elif defined(unix) || defined(__unix) || defined(__unix__) || defined(__APPLE__) 
  #include <sys/time.h>
  struct __bench__ {
    double sec() {
      struct timeval tv;
      gettimeofday(&tv, NULL);
      return tv.tv_sec + tv.tv_usec * 1e-6;
    }
    double start;
     __bench__() { start = sec(); }
    ~__bench__() { printf("%.6lf\n", sec() - start); }
    operator bool() { return false; }
  };
#else
  #error unsupported or unknown operating system
#endif
#define benchmark if ( __bench__ __b__ = __bench__()); else


int main(void) {
	int i, n = 100000000;

	float fa = 10.0f / (float)n;
	float fb;

	double da = 10.0 / (double)n;
	double db;

std::cout << "elaped-time of the loop" << std::endl;
	benchmark {
		for (i = 0; i < n; i++) {
		}
	}

std::cout << "1/x" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = 1.0f / fx;
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = 1.0 / dx;
			dx += da;
		}
	}

std::cout << "sin" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::sin(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::sin(dx);
			dx += da;
		}
	}

std::cout << "sinh" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::sinh(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::sinh(dx);
			dx += da;
		}
	}

std::cout << "asin" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::asin(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::asin(dx);
			dx += da;
		}
	}

std::cout << "tan" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::tan(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::tan(dx);
			dx += da;
		}
	}

std::cout << "tanh" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::tanh(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::tanh(dx);
			dx += da;
		}
	}

std::cout << "atan" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::atan(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::atan(dx);
			dx += da;
		}
	}

std::cout << "exp" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::exp(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::exp(dx);
			dx += da;
		}
	}

std::cout << "log" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::log(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::log(dx);
			dx += da;
		}
	}

std::cout << "sqrt" << std::endl;
	benchmark {
		float fx = fa;
		for (i = 0; i < n; i++) {
			fb = std::sqrt(fx);
			fx += fa;
		}
	}
	benchmark {
		double dx = da;
		for (i = 0; i < n; i++) {
			db = std::sqrt(dx);
			dx += da;
		}
	}

	return 0;
}
