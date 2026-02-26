// Intersection Observer for reveal animations
const observer = new IntersectionObserver(
    (entries) => {
        entries.forEach((entry) => {
            if (entry.isIntersecting) {
                entry.target.classList.add('vis');
            }
        });
    },
    { threshold: 0.08 }
);

document.querySelectorAll('.rev').forEach((el) => observer.observe(el));

// Interactive feature list (click to activate)
document.querySelectorAll('.fi').forEach((item) => {
    item.addEventListener('click', () => {
        document.querySelectorAll('.fi').forEach((i) => i.classList.remove('act'));
        item.classList.add('act');
    });
});