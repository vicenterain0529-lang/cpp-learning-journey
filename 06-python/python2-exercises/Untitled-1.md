business_inventory_system/

│
├── main.py
│
├── database/
│   ├── database.py
│   └── schema.py
│
├── models/
│   ├── product.py
│   ├── customer.py
│   └── transaction.py
│
├── inventory/
│   ├── add_product.py
│   ├── edit_product.py
│   ├── delete_product.py
│   ├── search_product.py
│   ├── update_stock.py
│   └── view_products.py
│
├── billing/
│   ├── cart.py
│   ├── checkout.py
│   └── receipt.py
│
├── reports/
│   ├── daily_report.py
│   └── inventory_report.py
│
├── utilities/
│   ├── validator.py
│   └── menu.py
│
├── data/
│   └── inventory.db
│
└── README.md

Products
product_id
product_code
name
category
price
stock
supplier
Customers
customer_id
name
address
phone
Transactions
transaction_id
customer_id
date
total
Transaction Items
transaction_item_id
transaction_id
product_id
quantity
price
subtotal



Stock History
history_id
product_id
change
reason
date


#methods sql

cursor.fetchone() → Gets the first row only.
cursor.fetchmany(size) → Gets a specified number of rows.
cursor.fetchall() → Gets all rows.