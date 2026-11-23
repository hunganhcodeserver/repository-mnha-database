.model small
.stack 100h
.data
  arr db 1, 2, 3, 4, 5  ; mảng 5 byte
.code
main proc
  mov ax, @data
  mov ds, ax

  mov al, 5             ; tức thì: AL = 5
  mov bl, al            ; thanh ghi: BL = 5
  mov al, arr           ; trực tiếp: AL = 1
  lea bx, arr           ; BX = địa chỉ arr
  mov al, [bx]          ; gián tiếp: AL = 1
  mov si, 2
  mov al, [bx+si]       ; chỉ số: AL = 3
  mov al, [bx+4]        ; tương đối: AL = 5
  mov ah, 2
  mov dl, al
  add dl, 48  ; số thành ký tự
  int 21h     ; in '5'

  mov ah, 4ch
  int 21h
main endp
end main
