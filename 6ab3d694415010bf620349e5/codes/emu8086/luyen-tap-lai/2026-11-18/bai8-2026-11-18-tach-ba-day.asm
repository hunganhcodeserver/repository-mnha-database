.model small
.stack 100h
.data
  ms1 db 'nhap day ky tu: $'
  ms2 db 13, 10, 'day ky tu vua nhap: $'
  ms3 db 13, 10, 'day chu hoa: $'
  ms4 db 13, 10, 'khong co chu hoa$'
  ms5 db 13, 10, 'day chu thuong: $'
  ms6 db 13, 10, 'khong co chu thuong$'
  ms7 db 13, 10, 'day so: $'
  ms8 db 13, 10, 'khong co so$'
  s   db 21 dup (?)  ; dãy nhập
  s1  db 21 dup (?)  ; chữ thường
  s2  db 21 dup (?)  ; chữ hoa
  s3  db 21 dup (?)  ; chữ số
.code
main proc
  mov ax, @data
  mov ds, ax         ; nạp DS
  mov ah, 9
  lea dx, ms1
  int 21h         ; in lời nhắc
  xor si, si      ; si = 0
nhap1:
  mov ah, 1
  int 21h
  cmp al, 13      ; là Enter?
  je stop1
  mov s[si], al   ; ghi vào ô si
  inc si
  cmp si, 20      ; đủ 20 ký tự?
  jb nhap1        ; si < 20: nhập tiếp
stop1:
  mov s[si], '$'  ; đóng chuỗi
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
  jb boquahoa     ; nhỏ hơn 'A': bỏ
  cmp al, 'Z'
  ja boquahoa     ; lớn hơn 'Z': bỏ
  mov s2[di], al  ; chép vào s2
  inc di
boquahoa:
  inc si
  jmp lochoa
stop2:
  mov s2[di], '$'   ; đóng s2
  cmp di, 0         ; có chữ hoa nào?
  je khongcochuhoa
  mov ah, 9
  lea dx, ms3
  int 21h
  lea dx, s2
  int 21h
  jmp locchuthuong  ; bỏ qua nhánh rỗng
khongcochuhoa:
  mov ah, 9
  lea dx, ms4
  int 21h
locchuthuong:
  xor si, si
  xor di, di      ; di = 0 (ghi s1)
lochthuong:
  cmp si, cx
  jae stop3
  mov al, s[si]
  cmp al, 'a'
  jb boquathuong  ; nhỏ hơn 'a': bỏ
  cmp al, 'z'
  ja boquathuong  ; lớn hơn 'z': bỏ
  mov s1[di], al  ; chép vào s1
  inc di
boquathuong:
  inc si
  jmp lochthuong
stop3:
  mov s1[di], '$'
  cmp di, 0
  je khongcochuthuong
  mov ah, 9
  lea dx, ms5
  int 21h
  lea dx, s1
  int 21h
  jmp locchuso
khongcochuthuong:
  mov ah, 9
  lea dx, ms6
  int 21h
locchuso:
  xor si, si
  xor di, di      ; di = 0 (ghi s3)
lochso:
  cmp si, cx
  jae stop4
  mov al, s[si]
  cmp al, '0'
  jb boquaso      ; nhỏ hơn '0': bỏ
  cmp al, '9'
  ja boquaso      ; lớn hơn '9': bỏ
  mov s3[di], al  ; chép vào s3
  inc di
boquaso:
  inc si
  jmp lochso
stop4:
  mov s3[di], '$'
  cmp di, 0
  je khongcoso
  mov ah, 9
  lea dx, ms7
  int 21h
  lea dx, s3
  int 21h
  jmp ketthuc  ; không rơi vào nhánh rỗng
khongcoso:
  mov ah, 9
  lea dx, ms8
  int 21h
ketthuc:
  mov ah, 4ch
  int 21h      ; thoát về DOS
main endp
end main
