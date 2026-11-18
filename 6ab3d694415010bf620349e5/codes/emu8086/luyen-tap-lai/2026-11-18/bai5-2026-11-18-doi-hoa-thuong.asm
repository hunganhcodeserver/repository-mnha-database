.model small
.stack 100h

.data
  tb1 db 'nhap ky tu: $'
  tb2 db 'ky tu sau khi doi: $'
  tb3 db 'day khong phai chu cai$'
.code
main proc
  mov ax, @data
  mov ds, ax       ; nạp DS

  mov ah, 9
  lea dx, tb1
  int 21h          ; in lời nhắc
  mov ah, 1
  int 21h          ; AL = ký tự vừa gõ
  mov bl, al       ; cất sang BL
  call xuond_dong  ; xuống dòng
  cmp bl, 'A'    ; so với 65
  jb kt_thuong   ; nhỏ hơn: không phải hoa
  cmp bl, 'Z'    ; so với 90
  ja kt_thuong   ; lớn hơn: không phải hoa
  add bl, 32     ; hoa thành thường
  jmp in_kq      ; nhảy sang in

kt_thuong:
  cmp bl, 'a'    ; so với 97
  jb khong_phai  ; nhỏ hơn: báo lỗi
  cmp bl, 'z'    ; so với 122
  ja khong_phai  ; lớn hơn: báo lỗi
  sub bl, 32     ; thường thành hoa
  jmp in_kq
khong_phai:
  mov ah, 9
  lea dx, tb3
  int 21h     ; in thông báo lỗi
  jmp thoat

in_kq:
  mov ah, 9
  lea dx, tb2
  int 21h     ; in lời nhắc kết quả
  mov ah, 2
  mov dl, bl  ; ký tự đã đổi
  int 21h     ; in ký tự
thoat:
  call xuond_dong  ; xuống dòng
  mov ah, 4ch
  int 21h          ; thoát về DOS
main endp

xuond_dong proc
  push ax          ; cất AX
  push dx          ; cất DX
  mov ah, 2
  mov dl, 13       ; về đầu dòng
  int 21h
  mov dl, 10       ; xuống dòng
  int 21h
  pop dx           ; trả DX
  pop ax           ; trả AX
  ret
xuond_dong endp
end main
