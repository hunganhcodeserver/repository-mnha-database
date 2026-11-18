.model small
.stack 100h
.data
  ms1 db 'nhap day ky tu: $'
  ms2 db 13, 10, 'day ky tu vua nhap: $'
  ms3 db 13, 10, 'day chu hoa: $'        ; có chữ hoa
  ms4 db 13, 10, 'khong co chu hoa$'     ; rỗng
  ms5 db 13, 10, 'day chu thuong: $'     ; có chữ thường
  ms6 db 13, 10, 'khong co chu thuong$'  ; rỗng
  ms7 db 13, 10, 'day so: $'             ; có chữ số
  ms8 db 13, 10, 'khong co so$'          ; rỗng
  ms9  db 13, 10, 'so chu hoa: $'     ; số lượng
  ms10 db 13, 10, 'so chu thuong: $'  ; số lượng
  ms11 db 13, 10, 'so chu so: $'      ; số lượng
  s    db 21 dup (?)                  ; dãy nhập
  s1   db 21 dup (?)                  ; chữ thường
  s2   db 21 dup (?)                  ; chữ hoa
  s3   db 21 dup (?)                  ; chữ số
.code
main proc
  mov ax, @data
  mov ds, ax                          ; nạp DS
  mov ah, 9      ; in lời nhắc
  lea dx, ms1
  int 21h
  xor si, si     ; si = 0
nhap1:
  mov ah, 1      ; hàm 1: đọc phím
  int 21h        ; AL = ký tự
  cmp al, 13     ; là Enter?
  je stop1
  mov s[si], al  ; ghi vào ô si
  inc si
  cmp si, 20     ; đủ 20 ký tự?
  jb nhap1       ; si < 20: nhập tiếp
stop1:
  mov s[si], '$'  ; đóng chuỗi s
  mov cx, si      ; cx = số ký tự
  mov ah, 9
  lea dx, ms2
  int 21h         ; in nhãn
  lea dx, s
  int 21h         ; in dãy vừa nhập
locchuhoa:
  xor si, si      ; si = 0 (đọc s)
  xor di, di      ; di = 0 (ghi s2)
lochoa:
  cmp si, cx      ; hết dãy?
  jae stop2
  mov al, s[si]
  cmp al, 'A'
  jb boquahoa     ; < 'A': bỏ
  cmp al, 'Z'
  ja boquahoa     ; > 'Z': bỏ
  mov s2[di], al  ; chép vào s2
  inc di          ; đếm thêm 1
boquahoa:
  inc si
  jmp lochoa
stop2:
  mov s2[di], '$'  ; đóng s2
  cmp di, 0        ; có chữ hoa?
  je khongcochuhoa
  mov ah, 9
  lea dx, ms3
  int 21h
  lea dx, s2
  int 21h
  jmp sochuhoa     ; qua nhánh rỗng
khongcochuhoa:
  mov ah, 9
  lea dx, ms4
  int 21h
sochuhoa:
  mov ah, 9
  lea dx, ms9
  int 21h
  mov ax, di  ; lấy DI ngay
  call in_so
locchuthuong:
  xor si, si      ; si = 0 (đọc s)
  xor di, di      ; di = 0 (ghi s1)
locthuong:
  cmp si, cx      ; hết dãy?
  jae stop3
  mov al, s[si]
  cmp al, 'a'
  jb boquathuong  ; < 'a': bỏ
  cmp al, 'z'
  ja boquathuong  ; > 'z': bỏ
  mov s1[di], al  ; chép vào s1
  inc di          ; đếm thêm 1
boquathuong:
  inc si
  jmp locthuong
stop3:
  mov s1[di], '$'  ; đóng s1
  cmp di, 0        ; có chữ thường?
  je khongcochuthuong
  mov ah, 9
  lea dx, ms5
  int 21h
  lea dx, s1
  int 21h
  jmp sochuthuong  ; qua nhánh rỗng
khongcochuthuong:
  mov ah, 9
  lea dx, ms6
  int 21h
sochuthuong:
  mov ah, 9
  lea dx, ms10
  int 21h
  mov ax, di  ; lấy DI ngay
  call in_so
locchuso:
  xor si, si      ; si = 0 (đọc s)
  xor di, di      ; di = 0 (ghi s3)
locso:
  cmp si, cx      ; hết dãy?
  jae stop4
  mov al, s[si]
  cmp al, '0'
  jb boquaso      ; < '0': bỏ
  cmp al, '9'
  ja boquaso      ; > '9': bỏ
  mov s3[di], al  ; chép vào s3
  inc di          ; đếm thêm 1
boquaso:
  inc si
  jmp locso
stop4:
  mov s3[di], '$'  ; đóng s3
  cmp di, 0        ; có chữ số?
  je khongcochuso
  mov ah, 9
  lea dx, ms7
  int 21h
  lea dx, s3
  int 21h
  jmp sochuso      ; qua nhánh rỗng
khongcochuso:
  mov ah, 9
  lea dx, ms8
  int 21h
sochuso:
  mov ah, 9
  lea dx, ms11
  int 21h
  mov ax, di  ; lấy DI ngay
  call in_so
ketthuc:
  mov ah, 4ch
  int 21h     ; thoát về DOS
main endp
in_so proc
  push ax
  push bx
  push dx     ; cất AX, BX, DX
  mov ah, 0   ; xoá AH trước div
  mov bl, 10  ; số chia
  div bl      ; AL = chục, AH = đơn vị
  mov bh, ah  ; cất đơn vị sang BH
  cmp al, 0    ; chục = 0?
  je donvi     ; bỏ số 0 đầu
  mov dl, al
  add dl, 30h  ; số → ký tự
  mov ah, 2
  int 21h      ; in chữ số chục
donvi:
  mov dl, bh
  add dl, 30h
  mov ah, 2
  int 21h      ; in chữ số đơn vị
  pop dx       ; ngược thứ tự push
  pop bx
  pop ax
  ret
in_so endp
end main
