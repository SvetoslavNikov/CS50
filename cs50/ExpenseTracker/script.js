
const incomeDescription = document.getElementById('income-description');
const incomeCategory = document.getElementById('income-category');
const incomeAmount = document.getElementById('income-amount');
const addIncomeButton = document.getElementById('add-income-button');


const expenseDescription = document.getElementById('expense-description');
const expenseCategory = document.getElementById('expense-category');
const expenseAmount = document.getElementById('expense-amount');
const addExpenseButton = document.getElementById('add-expense-button'); // Fixed typo in getElementById


const transactionHistory = document.getElementById('transaction-history');
const totalIncome = document.getElementById('total-income');
const totalExpense = document.getElementById('total-expense');
const balance = document.getElementById('balance');

const clearAllButton = document.getElementById('clear-all-button');
clearAllButton.addEventListener('click', clearAll);


addIncomeButton.addEventListener('click', handleIncomeAdd);
addExpenseButton.addEventListener('click', handleExpenseAdd);



function handleIncomeAdd() {
    const description = incomeDescription.value.trim();
    const amount = parseFloat(incomeAmount.value.trim());
    const category = incomeCategory.value;

    if (!validateTransaction(description, amount)) return;

    addTransaction(description, amount, category, 'Income');
    updateSummary();
    clearInputs('income');
}

function handleExpenseAdd() {
    const description = expenseDescription.value.trim();
    const amount = parseFloat(expenseAmount.value.trim());
    const category = expenseCategory.value;

    if (!validateTransaction(description, amount)) return;

    addTransaction(description, amount, category, 'Expense');
    updateSummary();
    clearInputs('expense');
}


function validateTransaction(description, amount) {
    if (description === '') {
        alert('Please enter a description');
        return false;
    }
    if (isNaN(amount) || amount <= 0) {
        alert('Please enter a valid amount :)');
        return false;
    }
    return true;
}


function addTransaction(description, amount, category, type) {
    const transactionRow = document.createElement('tr');


    transactionRow.innerHTML = `
        <td>${description}</td>
        <td>${category}</td>
        <td>${amount.toFixed(2)}</td>
        <td>${type}</td>
        <td><button class="delete-btn">X</button></td>
    `;


    const deleteBtn = transactionRow.querySelector('.delete-btn');
    deleteBtn.addEventListener('click', () => {
        transactionRow.remove();
        updateSummary();
    });

    transactionHistory.appendChild(transactionRow);
}


function updateSummary() {
    let sumExpense = 0;
    let sumIncome = 0;

    const transactions = transactionHistory.querySelectorAll('tr');

    transactions.forEach(transaction => {
        const amount = parseFloat(transaction.children[2].textContent);
        const type = transaction.children[3].textContent;

        if (type.toLowerCase() === 'expense') {
            sumExpense += amount;
        } else {
            sumIncome += amount;
        }
    });

    totalExpense.textContent = sumExpense.toFixed(2);
    totalIncome.textContent = sumIncome.toFixed(2);
    balance.textContent = (sumIncome - sumExpense).toFixed(2);
}


function clearInputs(type) {
    if (type === 'income') {
        incomeDescription.value = '';
        incomeAmount.value = '';
        incomeCategory.selectedIndex = 0;
    } else if (type === 'expense') {
        expenseDescription.value = '';
        expenseAmount.value = '';
        expenseCategory.selectedIndex = 0;
    }
}



function clearAll() {
    // Clear all transactions
    transactionHistory.innerHTML = '';
    // Reset summary
    totalIncome.textContent = '0';
    totalExpense.textContent = '0';
    balance.textContent = '0';
    // Clear inputs
    clearInputs('income');
    clearInputs('expense');
}
