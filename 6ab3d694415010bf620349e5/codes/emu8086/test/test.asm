.model small
.stack 100h
.data
ms1 db 'nhap day ki tu: $'
ms2 db 13, 10, 'day ky tu vua nhap: $'
ms3 db 13, 10, 'day chu hoa: $'
ms4 db 13, 10, 'khong co chu hoa$'
ms5 db 13, 10, 'day chu thuong: $'
ms6 db 13, 10, 'khong co chu thuong$'
ms7 db 13, 10, 'day so: $'
ms8 db 13, 10, 'khong co so$'
s db 21 dup (?)
s1 db 21 dup (?)
s2 db 21 dup (?)
s3 db 21 dup (?)
.code
 main proc
 
 mov ax, @data
 mov ds, ax
 
; =============================================================
; ======================NHAP DAY KI TU=========================
; =============================================================
 ; ====== in "nhap day ki tu: " ======
 mov ah, 9
 lea dx, ms1
 int 21h
 xor si, si ; si = 0 (chỉ số mảng s)
nhap1: 
 mov ah, 1
 int 21h
 cmp al, 13
 je stop1 ; gặp Enter thì thoát
 mov s[si], al ; lưu ký tự vừa nhập vào mảng s (s[0] -> s[20])
 inc si ; tăng chỉ số mảng s / sang ô kế tiếp
 cmp si, 20 ; kiểm tra xem đã nhập đủ 20 ký tự chưa
 jb nhap1 ; (jump if below): si < 20 thì quay lại nhập tiếp
stop1:
 mov s[si], '$' ; kết thúc chuỗi để in bằng hàm 9
 mov cx, si ; lưu số ký tự vừa nhập vào cx (cx = số ký tự đã nhập)
 ; ====== in "day ky tu vua nhap: " ======
 mov ah, 9
 lea dx, ms2
 int 21h
 ; ====== in "day ky tu vua nhap: " ======
 mov ah, 9
 lea dx, s
 int 21h
; =============================================================
; ======================LOC CHU HOA============================
; =============================================================
locchuhoa:
 xor si, si ; si = 0 (chỉ số đọc s)
 xor di, di ; di = 0 (di = chỉ số ghi s2)
lochoa:
 cmp si, cx ; đã duyệt hết chưa?
 jae stop2 ; si >= số ký tự thì thoát
 mov al, s[si] ; lấy ký tự thứ si trong mảng s
 ; ===================================================================
 ;JB (Jump if Below): Nhảy nếu "nhỏ hơn" (Jump if Below)
 ;JBE (Jump if Below or Equal): Nhảy nếu "nhỏ hơn hoặc bằng" (Jump if Below or Equal)
 ;JA (Jump if Above): Nhảy nếu "lớn hơn" (Jump if Above)
 ;JAE (Jump if Above or Equal): Nhảy nếu "lớn hơn hoặc bằng" (Jump if Above or Equal)
 cmp al, 'A' ; so sánh với 'A'
 jb boquahoa ; nếu al < 'A' thì bỏ qua ký tự này
 cmp al, 'Z' ; so sánh với 'Z'
 ja boquahoa ; nếu al > 'Z' thì bỏ qua ký tự này
 ; ===================================================================
 mov s2[di], al ; lưu ký tự hoa vào mảng s2
 inc di ; tăng chỉ số mảng s2 / sang ô kế tiếp
boquahoa:
 inc si ; tăng chỉ số mảng s / sang ô kế tiếp
 jmp lochoa ; quay lại kiểm tra ký tự tiếp theo
stop2:
 mov s2[di], '$' ; kết thúc chuỗi để in bằng hàm 9
 cmp di, 0 ; có chữ hoa nào không?
 je khongcochuhoa ; nếu cx = 0 thì nhảy đến không có chữ hoa
 ; ====== in "day chu hoa: " + dãy chữ hoa ======
 mov ah, 9
 lea dx, ms3
 int 21h
 mov ah, 9
 lea dx, s2
 int 21h
 ; jmp ketthuc
 jmp locchuthuong
khongcochuhoa:
 mov ah, 9
 lea dx, ms4
 int 21h
; =============================================================
; ======================LOC CHU THUONG=========================
; =============================================================
locchuthuong:
 xor si, si ; si = 0 (chỉ số đọc s)
 xor di, di ; di = 0 (di = chỉ số ghi s3)
locthuong:
 cmp si, cx ; đã duyệt hết chưa?
 jae stop3 ; si >= số ký tự thì thoát
 mov al, s[si] ; lấy ký tự thứ si trong mảng s
 ; ===================================================================
 ;JB (Jump if Below): Nhảy nếu "nhỏ hơn" (Jump if Below)
 ;JBE (Jump if Below or Equal): Nhảy nếu "nhỏ hơn hoặc bằng" (Jump if Below or Equal)
 ;JA (Jump if Above): Nhảy nếu "lớn hơn" (Jump if Above)
 ;JAE (Jump if Above or Equal): Nhảy nếu "lớn hơn hoặc bằng" (Jump if Above or Equal)
 cmp al, 'a' ; so sánh với 'a'
 jb boquathuong ; nếu al < 'a' thì bỏ qua ký tự này
 cmp al, 'z' ; so sánh với 'z'
 ja boquathuong ; nếu al > 'z' thì bỏ qua ký tự này
 ; ===================================================================
 mov s1[di], al ; lưu ký tự thường vào mảng s1
 inc di ; tăng chỉ số mảng s1 / sang ô kế tiếp
boquathuong:
 inc si ; tăng chỉ số mảng s / sang ô kế tiếp
 jmp locthuong ; quay lại kiểm tra ký tự tiếp theo
stop3:
 mov s1[di], '$' ; kết thúc chuỗi để in bằng hàm 9
 cmp di, 0 ; có chữ thường nào không?
 je khongcochuthuong ; nếu cx = 0 thì nhảy đến không có chữ thường
 ; ====== in "day chu thuong: " + dãy chữ thường ======
 mov ah, 9
 lea dx, ms5 ; "day chu thuong: "
 int 21h
 mov ah, 9
 lea dx, s1
 int 21h
 ; jmp ketthuc
 jmp locchuso
khongcochuthuong:
 mov ah, 9
 lea dx, ms6 ; "khong co chu thuong"
 int 21h
; =============================================================
; ======================LOC SO=================================
; =============================================================
locchuso:
 xor si, si ; si = 0 (chỉ số đọc s)
 xor di, di ; di = 0 (di = chỉ số ghi s3)
locso:
 cmp si, cx ; đã duyệt hết chưa?
 jae stop4 ; si >= số ký tự thì thoát
 mov al, s[si] ; lấy ký tự thứ si trong mảng s
 ; ===================================================================
 ;JB (Jump if Below): Nhảy nếu "nhỏ hơn" (Jump if Below)
 ;JBE (Jump if Below or Equal): Nhảy nếu "nhỏ hơn hoặc bằng" (Jump if Below or Equal)
 ;JA (Jump if Above): Nhảy nếu "lớn hơn" (Jump if Above)
 ;JAE (Jump if Above or Equal): Nhảy nếu "lớn hơn hoặc bằng" (Jump if Above or Equal)
 cmp al, '0' ; so sánh với '0'
 jb boquaso ; nếu al < '0' thì bỏ qua ký tự này
 cmp al, '9' ; so sánh với '9'
 ja boquaso ; nếu al > '9' thì bỏ qua ký tự này
 ; ===================================================================
 mov s3[di], al ; lưu ký tự số vào mảng s3
 inc di ; tăng chỉ số mảng s3 / sang ô kế tiếp
boquaso:
 inc si ; tăng chỉ số mảng s / sang ô kế tiếp
 jmp locso ; quay lại kiểm tra ký tự tiếp theo
stop4:
 mov s3[di], '$' ; kết thúc chuỗi để in bằng hàm 9
 cmp di, 0 ; có số nào không?
 je khongcoso ; nếu di = 0 thì nhảy đến không có số
 ; ====== in "day so: " + dãy số ======
 mov ah, 9
 lea dx, ms7 ; "day so: "
 int 21h
 mov ah, 9
 lea dx, s3
 int 21h
 jmp ketthuc
khongcoso:
 mov ah, 9
 lea dx, ms8 ; "khong co so"
 int 21h
ketthuc: 
 mov ah, 4ch
 int 21h
 main endp
end main