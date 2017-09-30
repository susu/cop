
example:
	$(MAKE) -C examples all

test:
	$(MAKE) -C tests

check: test
	$(MAKE) -C tests check

clean:
	$(MAKE) -C examples clean
	$(MAKE) -C tests clean

