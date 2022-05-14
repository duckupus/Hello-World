#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t quack() { /* H */
	return 72;
}

uint8_t ee(uint8_t e) { /* e */
	e = ~e; e >>= 5;
	e |= 0x20;
	e ^= 0x1a;
	e &= 0xf5;
	e -= 0x27;
	e |= 0x90;
	e = ~e;
	return e;
}

uint8_t ll11(uint8_t l1) { /* l(first one) */
	return l1 ^ 0x43;
}

uint32_t ll22(uint32_t x) { /* l(second one) */
	uint32_t i = 0x0;
	for(; i<0xdeadbeef; i = -~i) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
	}
	return x;
}

uint8_t oh() { /* o(first one) */
	int diff, val=0xff;
	char buf[1024] = "FuFuFuFuFuFu";
	for(int i=0; i< sizeof(buf); i++) {
		buf[i] |= val;
	}
	diff = (char *) &val - (char *) &buf[133];
	return diff;
}

uint8_t space(uint8_t count) { /* space */
	if(count > 0) {
		return space(count - 1) + count;
	} else
		return 0;
}

uint8_t ddub(uint8_t x) { /* W */
	char buf[128];
	char buffer[256];
	int i;
	int tmp;
	for(i = 0; i < 10; i++) {
		buf[i] = 0x7;
	}
	for(; i < 40; i++) {
		buf[i] = 0xfe;
	}
	for(; i < 85; i++) {
		buf[i] = 0xae;
	}
	buf[86] = 0x11;
	buf[87] = 0x00;
	sprintf(buffer, "%s%n", buf, &tmp);
	return x = tmp;
}

uint8_t ohhh(uint8_t x) { /* o(second one) */
	char val[] = "stuffz go brr";
	char buf[] = "thingS GO hrr";
	for(int i = 0; i < sizeof(val); i++) {
		x += val[i] - buf[i];
	}
	return x;
}

uint8_t brr(uint8_t x) { /* r */
	int prrr;
	int *ptr[100];
	int c = 0;
	int j = 1;
	while(c <= 100) {
		j++;
		prrr = 1;
		if(j % 2 == 0)
			continue;
		for(int q=3; q<= j/2; q+=2) {
			if(j % q == 0) {
				prrr=0;
				break;
			}
		}
		if(prrr==1) {
			ptr[c] = malloc(sizeof(int));
			*ptr[c] = j;
			c++;
		}
	}
	x = *ptr[74] - *ptr[55];
	for(int i=0; i < 100; i++) { //cleanup
		free(ptr[i]);
	}
	return x;
}

uint8_t lk(uint8_t x) { /* l */
	struct node {
		struct node *next;
		uint8_t val;
	};
	struct node h, e, l, o, w, r, d;
	h.next = &e;
	h.val = x;
	e.next = &l;
	e.val = x<<2 ^ 3;
	l.next = &o;
	l.val = x | (x-1);
	o.next = &w;
	o.val = (x==h.val);
	w.next = &r;
	w.val = e.val - 0x32;
	r.next = &d;
	r.val = w.val & l.val;
	d.next = NULL;
	d.val = (char*)r.next-(char*)h.next;
	x = 0x0;
	x ^= h.next->next->next->next->val;
	x >>= 4;
	h.next->next->next->val += x;
	x = h.next->next->next->val;
	h.next->next->next->val <<= 4;
	x &= h.next->val;
	x ^= h.val;
	x ^= h.next->next->next->next->next->next->val;
	x >>= 4;
	x = ~(x & h.next->next->val);
	x &= 0xf;
	x |= h.next->next->next->val;
	return x;
}

uint8_t de(uint64_t val) { /* d */
	uint64_t p=2, ptr[10];
	int flag=0;
	int current=0;
	while(p <= val) {
		if(0x0 == (val % p)) {
			if(flag != 1) {
				ptr[current] = p;
				current++;
				flag = 1;
			}
			val = val / p;
		} else {
			p++;
			flag = 0;
		}
	}
	val = ptr[2] - ptr[1];
	val = val % 111;
	return val;
}

uint8_t endl(uint8_t x) { /* \n */
	return x + 5 - 8 * 4 - 2*(32 - 31);
}

int main() {
	uint8_t H = quack();
	putchar(H); //H

	uint8_t e = ee(0x88);
	putchar(e); //e

	uint8_t l1 = ll11(0x2f);
	putchar(l1); //l

	uint32_t x = ll22(0x73780d2a);
	putchar(x); //l

	uint8_t o = oh();
	putchar(o); //o

	uint8_t spac = space(8)-4;
	putchar(spac); //space

	uint8_t dub = ddub(0x0b);
	putchar(dub); //W

	uint8_t o2 = ohhh(0x0);
	putchar(o2); //o

	uint8_t r = brr(0x0);
	putchar(r); //r

	uint8_t lmk = lk(0xa2);
	putchar(lmk); //l

	uint8_t d = de(0x4094b826d7e8f0c0);
	putchar(d); //d

	uint8_t oldline = endl(0x27);
	putchar(oldline); // \n
	return 0;
}
