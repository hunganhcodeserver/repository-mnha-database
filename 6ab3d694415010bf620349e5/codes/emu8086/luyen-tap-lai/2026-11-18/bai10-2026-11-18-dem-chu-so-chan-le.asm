.model small
.stack 100h
.data
  ms1 db 'nhap day so: $'
  ms2 db 13, 10, 'day so vua nhap: $'
  ms3 db 13, 10, 'so chu so chan: $'
  ms4 db 13, 10, 'so chu so le: $'
  s   db 21 dup (?)  ; 20 ký tự + $
.code
main proc
  mov ax, @data
  mov ds, ax         ; nạp DS

  mov ah, 9
  lea dx, ms1
  int 21h            ; in lời nhắc

  xor si, si         ; si = 0
nhap:
  mov ah, 1
  int 21h         ; AL = ký tự vừa gõ
  cmp al, 13      ; là Enter?
  je stop1        ; đúng thì dừng
  mov s[si], al   ; cất vào ô si
  inc si
  cmp si, 20      ; đủ 20 ký tự?
  jb nhap         ; si < 20: nhập tiếp
stop1:
  mov s[si], '$'  ; đóng chuỗi s
  mov ah, 9
  lea dx, ms2
  int 21h         ; in nhãn
  lea dx, s
  int 21h         ; in dãy vừa nhập
  xor si, si     ; si = 0
  xor bx, bx     ; BL = chẵn, BH = lẻ
duyet:
  mov al, s[si]  ; lấy ký tự
  cmp al, '$'    ; hết dãy?
  je xong
  cmp al, '0'
  jb tiep        ; nhỏ hơn '0': bỏ qua
  cmp al, '9'
  ja tiep        ; lớn hơn '9': bỏ qua
  mov ah, 0      ; AX = mã ASCII
  mov cl, 2      ; số chia
  div cl         ; AH = số dư
  cmp ah, 0      ; dư 0?
  jne so_le      ; dư 1: số lẻ
  inc bl         ; số chẵn
  jmp tiep
so_le:
  inc bh         ; số lẻ
tiep:
  inc si
  jmp duyet

xong:
  mov ah, 9
  lea dx, ms3
  int 21h     ; in 'so chu so chan: '
  mov al, bl
  call in_so  ; in BL
  mov ah, 9
  lea dx, ms4
  int 21h     ; in 'so chu so le: '
  mov al, bh
  call in_so  ; in BH
  mov ah, 4ch
  int 21h     ; thoát về DOS
main endp
in_so proc
  push ax
  push bx
  push dx      ; cất AX, BX, DX
  mov ah, 0    ; xoá AH trước div
  mov bl, 10   ; số chia
  div bl       ; AL = chục, AH = đơn vị
  mov bh, ah   ; cất đơn vị sang BH
  cmp al, 0    ; chục = 0?
  je donvi     ; bỏ số 0 đầu
  mov dl, al
  add dl, 30h  ; số thành ký tự
  mov ah, 2
  int 21h      ; in chữ số chục
donvi:
  mov dl, bh
  add dl, 30h
  mov ah, 2
  int 21h  ; in chữ số đơn vị
  pop dx   ; ngược thứ tự push
  pop bx
  pop ax
  ret
in_so endp
end main
