mov dptr,#0x4500
movx a,@dptr
mov b,a
inc dptr
movx a,@dptr
div ab
inc dptr
movx @dptr,a
mov a,b
inc dptr
movx @dptr,a
end