	global main

	section .text

	main	:
	enter	0,0
	int	0x80
	leave
	ret