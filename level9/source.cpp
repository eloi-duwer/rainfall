#include <cstring>

class N {

public:
	N(int nb) {
		this->n = nb;
	}

	int operator+(N &n) {
		return (this->n + n.n);
	}

	int operator-(N &n) {
		return (n.n - this->n);
	}

	void *setAnnotation(char *s) {
		return (memcpy(this->s + 4, s, strlen(s))); // I'm not sure about the + 4, it seems to be the intent of the instruction at 0x08048722 ?
	}

private:
	int		n; //0x68(%eax)
	char	s[100]; //The class takes 0x6c (104) bytes (seen on the call to new), so I assume there is an int and 100 chars
};

int main(int argc, char **argv) {
	N	*ptb; //0x10(%esp)
	N	*pta; //0x14(%esp)
	N	*b;   //0x18(%esp)
	N	*a;   //0x1c(%esp)

	if (argc <= 1)
		_exit(1);
	
	a = new N(5);
	b = new N(6);
	pta = a;
	ptb = b;
	pta->setAnnotation(argv[1]);
	(**ptb)(ptb, pta);
}
