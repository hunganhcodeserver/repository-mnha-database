; cach 1: cmp + jle
.model small
.stack 100h
.code
main proc
  mov dl, 'A'
intiep:
  mov ah, 2
  int 21h      ; in DL
  add dl, 1    ; ký tự kế
  cmp dl, 'Z'  ; DL <= Z thì lặp
  jle intiep
  mov ah, 4ch
  int 21h
main endp
end main
