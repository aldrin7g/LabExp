mov dptr,#4100H
movx a,@dptr
mov b,a
inc dptr
movx a,@dptr
anl a,b
inc dptr
movx @dptr,a
end