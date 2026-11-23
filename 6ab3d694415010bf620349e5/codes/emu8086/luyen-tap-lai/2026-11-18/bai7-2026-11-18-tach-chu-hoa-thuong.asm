.model small
.stack 100h
.data
  s   db 21 dup(?)  ; dãy nhập (20 ký tự + $)
  s1  db 21 dup(?)  ; chữ thường
  s2  db 21 dup(?)  ; chữ hoa
  ms1 db 'nhap day ky tu: $'
  ms2 db 10, 13, 'day ky tu vua nhap: $'
  ms3 db 10, 13, 'day chu hoa: $'
  ms4 db 10, 13, 'day chu thuong: $'
.code
main proc
  mov ax, @data
  mov ds, ax        ; nạp DS

  mov ah, 9
  lea dx, ms1
  int 21h           ; in lời nhắc
  lea si, s         ; SI trỏ đầu mảng s
nhap:
  mov ah, 1
  int 21h                 ; AL = ký tự
  cmp al, 13              ; là Enter?
  je xong_nhap            ; đúng thì dừng
  mov [si], al            ; cất vào ô SI trỏ tới
  inc si                  ; sang ô kế
  jmp nhap

xong_nhap:
  mov byte ptr [si], '$'  ; đóng chuỗi
  mov ah, 9
  lea dx, ms2
  int 21h                 ; in ms2
  lea dx, s
  int 21h                 ; in dãy vừa nhập
  lea si, s     ; SI: đọc từ s
  lea di, s2    ; DI: ghi chữ hoa
  lea bx, s1    ; BX: ghi chữ thường
duyet:
  mov al, [si]  ; lấy ký tự
  cmp al, '$'   ; hết dãy?
  je xong_tach  ; hết thì dừng
  cmp al, 'a'   ; so với 'a' (97)
  jb hoa        ; nhỏ hơn: chữ hoa
  mov [bx], al  ; chữ thường vào s1
  inc bx
  jmp tiep      ; bỏ qua nhánh hoa
hoa:
  mov [di], al  ; chữ hoa vào s2
  inc di
tiep:
  inc si        ; ký tự kế của s
  jmp duyet
xong_tach:
  mov byte ptr [bx], '$'  ; đóng s1
  mov byte ptr [di], '$'  ; đóng s2
  mov ah, 9
  lea dx, ms3
  int 21h
  lea dx, s2
  int 21h                 ; in chữ hoa
  lea dx, ms4
  int 21h
  lea dx, s1
  int 21h                 ; in chữ thường
  mov ah, 4ch
  int 21h                 ; thoát về DOS
main endp
end main
