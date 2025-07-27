mov dptr,#4100H
movx a,@dptr
cpl a
inc dptr
movx @dptr,a
end