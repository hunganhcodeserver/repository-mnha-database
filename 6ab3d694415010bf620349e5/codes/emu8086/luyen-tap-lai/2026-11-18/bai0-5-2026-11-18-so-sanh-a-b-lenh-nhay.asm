.model small
.stack 100h
.data
  ms1 db 'a lon hon b$'
  ms2 db 'a nho hon b$'
.code
main proc
  mov ax, @data
  mov ds, ax
  mov bh, 3   ; a = 3
  mov bl, 5   ; b = 5
  cmp bh, bl  ; so sánh a với b
  jg lonhon   ; a > b thì nhảy
  mov ah, 9
  lea dx, ms2
  int 21h  ; in 'a nho hon b'
  jmp kt   ; bỏ qua nhánh kia

lonhon:
  mov ah, 9
  lea dx, ms1
  int 21h  ; in 'a lon hon b'
kt:
  mov ah, 4ch
  int 21h  ; thoát về DOS
main endp
end main
