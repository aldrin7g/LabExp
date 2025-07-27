mov dptr,#0x4500
movx a,@dptr
mov b,a
inc dptr
movx a,@dptr
mul ab
mov r0, a
mov a, b
inc dptr
movx @dptr,a
mov a, r0
inc dptr
movx @dptr,a
end