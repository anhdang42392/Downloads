#!/usr/bin/bash






faculty_file="Danh sach Khoa.txt"
lecturer_file="Danh sach Giang Vien.txt"


add_faculty() {
    echo "Faculty Code:"
    read faculty_id
    echo "Name falcuty:"
    read faculty_name
    echo "name leader:"
    read head_of_faculty
    echo "$faculty_id, $faculty_name, $head_of_faculty" >> "$faculty_file"
    echo "Successful"
}


add_lecturer() {
    echo "ID teacher:"
    read faculty_id
    echo "Location of teacher"
    read position
    echo "name of teacher"
    read lecturer_name
    echo "$faculty_id, $position, $lecturer_name" >> "$lecturer_file"
    echo "Đã thêm giảng viên thành công!"
}


display_faculties() {
    echo "Danh sách các khoa:"
    if [[ -f "$faculty_file" ]]; then
        cat "$faculty_file"
    else
        echo "Không có khoa nào trong danh sách."
    fi
}

display_lecturers() {
    echo "Danh sách giảng viên:"
    if [[ -f "$lecturer_file" ]]; then
        cat "$lecturer_file"
    else
        echo "Không có giảng viên nào trong danh sách."
    fi

    }


search_faculty() {
    echo "Nhập tên hoặc mã khoa cần tìm kiếm:"
    read search_faculty
    grep -i "$search_faculty" "$faculty_file" || echo "Không tìm thấy khoa nào với từ khóa $search_faculty."
}


search_lecturer() {
    echo "Nhập tên hoặc mã khoa của giảng viên cần tìm kiếm:"
    read search_lecturer
    grep -i "$search_lecturer" "$lecturer_file" || echo "Không tìm thấy giảng viên nào với từ khóa $search_lecturer."
}


while true; do
    echo "====== Quản lý Giảng viên và Khoa ======"
    echo "1. Thêm khoa"
    echo "2. Thêm giảng viên"
    echo "3. Hiển thị danh sách khoa"
    echo "4. Hiển thị danh sách giảng viên"
    echo "5. Tìm kiếm khoa"
    echo "6. Tìm kiếm giảng viên"
    echo "0. Thoát"
    echo "========================================"
    echo "Nhập lựa chọn của bạn:"
    read choice

    case $choice in
        1) add_faculty ;;
        2) add_lecturer ;;
        3) display_faculties ;;
        4) display_lecturers ;;
        5) search_faculty ;;
        6) search_lecturer ;;
        0) echo "Out"; break ;;
        *) echo "Failef. pick again" ;;
    esac
done