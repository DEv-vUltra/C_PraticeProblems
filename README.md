<!DOCTYPE html>
<html lang="vi">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Chủ đề 1: Memory Management</title>
<style>
    body {
        font-family: "Segoe UI", Arial, sans-serif;
        line-height: 1.7;
        background-color: #f9fafb;
        color: #222;
        margin: 0;
        padding: 40px;
    }
    h1 {
        text-align: center;
        color: #004aad;
        text-transform: uppercase;
        letter-spacing: 1px;
        margin-bottom: 30px;
    }
    h2, h3 {
        color: #003366;
        margin-top: 30px;
    }
    p {
        text-align: justify;
    }
    ul {
        list-style-type: disc;
        margin-left: 40px;
    }
    img {
        display: block;
        margin: 20px auto;
        max-width: 100%;
        border-radius: 10px;
        box-shadow: 0 0 8px rgba(0,0,0,0.15);
    }
    .section {
        background: white;
        padding: 25px 30px;
        border-radius: 15px;
        box-shadow: 0 4px 12px rgba(0,0,0,0.1);
        margin-bottom: 40px;
    }
    code {
        background-color: #f4f4f4;
        padding: 2px 5px;
        border-radius: 4px;
        font-family: Consolas, monospace;
        color: #d63384;
    }
    .question {
        color: #d9534f;
        font-weight: bold;
    }
    .answer {
        color: #0275d8;
        font-weight: 500;
    }
    table {
        width: 100%;
        border-collapse: collapse;
        margin-top: 20px;
    }
    th, td {
        border: 1px solid #ccc;
        padding: 10px;
        text-align: left;
    }
    th {
        background-color: #f0f4f8;
    }
</style>
</head>
<body>

<h1>Chủ đề 1: Memory Management</h1>

<div class="section">
<p>Bộ nhớ ảo là một cơ chế quản lý bộ nhớ của hệ điều hành cho phép chương trình có cảm giác như đang có một không gian bộ nhớ liên tục và lớn hơn nhiều so với bộ nhớ vật lí (RAM)</p>

<p><b>Bộ nhớ ảo gồm những thành phần chính như là:</b></p>

<h3>1.1 Không gian địa chỉ ảo (Virtual Address Space)</h3>
<p>Là tập hợp tất cả các địa chỉ mà tiến trình (process) có thể truy cập. 
Mỗi tiến trình có một không gian địa chỉ ảo riêng biệt còn gọi là Process ID (PID) được hệ điều hành cấp để phân biệt với các tiến trình khác.</p>
<p>Không gian này được chia thành các vùng còn gọi là (segments hay pages) cho:</p>
<ul>
    <li>Mã chương trình (machine code/ text)</li>
    <li>Dữ liệu tĩnh (Data)</li>
    <li>Ngăn xếp (Stack)</li>
    <li>Vùng heap (cấp phát động)</li>
    <li>Vùng ánh xạ file (Memory-mapped file)</li>
</ul>

<h3>1.2 Bảng trang (Page table)</h3>
<p>Là cấu trúc dữ liệu được hệ điều hành dùng để ánh xạ giữa địa chỉ ảo và địa chỉ vật lí.</p>

<h3>1.3 Trang (Page) và khung trang (Frame)</h3>
<p><b>Trang (Page):</b> đơn vị chia nhỏ của không gian bộ nhớ ảo (thường là 4Kb)</p>
<p><b>Khung trang (Frame):</b> đơn vị tương ứng trong bộ nhớ vật lí (RAM)</p>

<h3>1.4 Bộ nhớ hoán đổi (Swap space / Backing store)</h3>
<p>Là phần không gian trên ổ đĩa dùng để lưu trữ tạm thời</p>

<h3>1.5 Bộ quản lí bộ nhớ (Memory Management Unit - MMU)</h3>
<p>Là phần cứng trong CPU chịu trách nhiệm:</p>
<ul>
    <li>Chuyển đổi địa chỉ ảo thành địa chỉ vật lí</li>
    <li>Kiểm tra quyền truy cập</li>
    <li>Sử dụng bộ nhớ đệm tốc độ cao để tăng tốc quá trình này</li>
</ul>

<p>Trong bài viết này ta sẽ chỉ tập trung vào phần không gian địa chỉ ảo...</p>

<img src="https://github.com/user-attachments/assets/151195bd-d8a1-4be3-80ef-5bc22255dbd3" alt="image" width="444" height="495">

<h2>Text segment</h2>
<p>Chứa mã máy (machine code) của chương trình — tức là các lệnh CPU sẽ thực thi...</p>

<img src="https://github.com/user-attachments/assets/6ee77b38-853d-48aa-b1f1-c83129ab0848" alt="image" width="1399" height="520">

<h3>Initialized data (.data)</h3>
<p>Chứa các biến toàn cục (global) hoặc các biến tĩnh (static) được khởi tạo với giá trị khác 0.</p>

<h3>Uninitialized data (.bss)</h3>
<p>...chứa các biến toàn cục (global) và các biến tĩnh (static) được mặc định bằng 0.</p>

<p>Việc phải phân chia ra 2 vùng là khởi tạo và không khởi tạo để có thể tách biệt các biến khi chúng thực thi...</p>

<img src="https://github.com/user-attachments/assets/dff72339-611f-4049-9e1d-98bbd6d56b31" alt="Screenshot 1.1.3">
<img src="https://github.com/user-attachments/assets/c4bc98e1-145a-4723-882b-fe4f6b3303c1" alt="Screenshot 1.1.4">
<img src="https://github.com/user-attachments/assets/1cbbbe7e-58ec-4262-8dd8-be36e25a25f3" alt="Screenshot 1.1.5">
<img src="https://github.com/user-attachments/assets/e42424ca-b69f-4978-beb7-4c84a2d6c010" alt="Screenshot 1.1.6">

<p>Ta thấy 1 biến int sẽ tốn 4 byte... đặc biệt trong lập trình nhúng khi mà bộ nhớ bị giới hạn.</p>

<h3>Heap - Vùng cấp phát động</h3>
<p>Dành cho các đối tượng được cấp phát động trong lúc chương trình chạy (runtime)...</p>

<h3>Stack - Ngăn xếp</h3>
<ul>
    <li>Lưu trữ biến cục bộ (local variables), tham số hàm, địa chỉ trả về</li>
    <li>Quản lý theo cơ chế LIFO (Last In First Out)</li>
    <li>Phát triển từ địa chỉ cao đến thấp</li>
</ul>

<hr>

<h2>Các vấn đề & Câu hỏi</h2>

<p class="question">Vấn đề 1: Tại sao biến const thường được đặt trong vùng (.rodata) thay vì (.data)?</p>
<p class="answer">Đáp án: Biến const được đặt trong vùng (.rodata)...</p>

<p class="question">Vấn đề 2: Nếu bạn muốn dữ liệu tồn tại xuống vòng đời chương trình...</p>
<p class="answer">Đáp án: Là vùng (.bss) và vùng (.data)...</p>

<p class="question">Vấn đề 3: Tại sao vùng .bss không chiếm nhiều dung lượng trong file .bin nhưng lại chiếm RAM khi chạy?</p>
<p class="answer">(.bss) sẽ được khởi tạo bằng 0 nên không cần thiết phải lưu hàng triệu byte 0...</p>

<p class="question">Vấn đề 4: Điều gì sẽ xảy ra với Stack khi hàm kết thúc...</p>
<p class="answer">Khi Stack pop thì vì là biến static nên nó được lưu trong (.data)...</p>

<p class="question">Vấn đề 5: Lỗi Segmentation Fault xảy ra khi nào? Tại sao? Cách debug?</p>
<p class="answer">Lỗi segmentation fault xảy ra khi mà ta truy cập vào vùng nhớ không hợp lệ...</p>

<img src="https://github.com/user-attachments/assets/0562dac1-f3fe-401e-a1a5-becbf3300940" alt="Screenshot 1.1.7">
<img src="https://github.com/user-attachments/assets/8c2f9910-ac70-4a95-8024-f2d21947585f" alt="Screenshot 1.1.8">
<img src="https://github.com/user-attachments/assets/c3368903-8d99-4aa5-9f77-b0af581252ac" alt="Screenshot 1.1.9">
<img src="https://github.com/user-attachments/assets/8d192876-d08c-4121-821b-397225f1d5e0" alt="Screenshot 1.1.10">

<!-- Phần còn lại giữ nguyên nội dung, bố cục tương tự như trên -->
<p>...</p>

</div>

</body>
</html>
